(setq inhibit-startup-message t)

(defconst not-mswin (not (eq system-type 'windows-nt)) "MS윈도우가 아니면 참")

(add-to-list 'load-path "~/.emacs.d/yasnippet")
(require 'yasnippet)
(yas/initialize)
(yas/load-directory "~/.emacs.d/yasnippet/snippets")

(add-to-list 'load-path "~/.emacs.d/emf")
(autoload 'expand-member-functions "member-functions" "Expand C++ member function declarations" t)
(add-hook 'c++-mode-hook (lambda () (local-set-key "\C-cm" 'expand-member-functions)))

(fset 'yes-or-no-p 'y-or-n-p)

(add-to-list 'load-path "~/.emacs.d/ecb-snap/")
(require 'ecb-autoloads)
;;(load "~/.emacs.d/ecb-snap")
;;(load "~/.emacs.d/_personal-plugins_/ecb-snippets")

(global-cwarn-mode 1)
(setnu-mode 1)

(load-file "~/.emacs.d/cedet-cvs/common/cedet.el")
(global-ede-mode 1)
(require 'semantic-ia)
(global-semanticdb-minor-mode 1)
(semantic-load-enable-minimum-features)
(semantic-load-enable-code-helpers)
(setq semanticdb-default-save-directory "~/.emacs.d/#semanticdb.cache#")
(semantic-add-system-include "/usr/include/gtkmm-2.4/" 'c++-mode)

(global-set-key [(control return)] 'semantic-ia-complete-symbol-menu)
(global-set-key [(control shift return)] 'semantic-ia-complete-tip)
(global-set-key [(control c)(control return)] 'semantic-complete-analyze-inline)
(global-set-key [(shift return)] 'semantic-analyze-possible-completions)

;;;; 심볼완성 키바인딩 예제
;; M-/ (dabbrev-expand) - emacs에 기본 설정 되어 있음
;;senator-complete-symbol 기본 키바인딩은 C-c , TAB 이고 아래는 추가 지정한 것임
(global-set-key [(meta return)] 'senator-complete-symbol)
(global-set-key [(meta shift return)] 'complete-symbol)
;; ebrowse-tags-complete-symbol 기본 키바인딩은 C-c RET TAB 이고 아래는 추가 지정한 것임
(global-set-key [(control meta return)] 'ebrowse-tags-complete-symbol)

;;;; == 기본 색상 및 위치 변경 ==
;; emacs 자체 customize에서 배경 및 글자색 변경하면 semantic-ia-complete-tip 글자가 안보이기 때문에 여기서 지정
(add-to-list 'initial-frame-alist '(foreground-color . "white"))
(add-to-list 'initial-frame-alist '(background-color . "black"))
;; default-frame과 구별위해 필요, 크기는 default-frame에서만 지정해도 됨
;;(add-to-list 'initial-frame-alist '(left . 80))
;;(add-to-list 'initial-frame-alist '(top . 80))

;;(add-to-list 'default-frame-alist '(left . 120))
;;(add-to-list 'default-frame-alist '(top . 120))
;;(add-to-list 'default-frame-alist '(width . 140))
;;(add-to-list 'default-frame-alist '(height . 50))
;; 이렇게 하면 semantic-ia-complete-tip 글자가 안보인다. after-make-frame-functions로 옮김 
;;(add-to-list 'default-frame-alist '(foreground-color . "white"))
;;(add-to-list 'default-frame-alist '(background-color . "black"))


;;;; == make-frame로 만들어진 frame의 modeline 색상 변경 == 
(defun change-modeline-color (newframe)
  (set-face-foreground 'default "white" newframe)
  (set-face-background 'default "black" newframe)
  (set-face-background 'modeline "DarkOrange4" newframe)
  )
(add-hook 'after-make-frame-functions 'change-modeline-color)

;; * rectangle-mark
;; 사각형으로 영역 선택 반전이 가능하도록
(load "~/.emacs.d/rectangle-mark")

;; * smart compile, mode compile
(load "~/.emacs.d/compile/compile-snippets")

;; * tags-snippets
(load "~/.emacs.d/tags-snippets")

;; * 괄호 짝 맞추는 기능 vi %명령과 같음
(show-paren-mode t)


;;;; == screen-lines-mode ==
;; longlines-mode와 비슷하시지만 좀더 직관적임, vim의 gj, gk 와 비슷
(add-to-list 'load-path "~/.emacs.d/screen-lines")
(autoload 'screen-lines-mode "screen-lines"
  "Toggle Screen Lines minor mode for the current buffer." t)
(autoload 'turn-on-screen-lines-mode "screen-lines"
  "Turn on Screen Lines minor mode for the current buffer." t)
(autoload 'turn-off-screen-lines-mode "screen-lines"
  "Turn off Screen Lines minor mode for the current buffer." t)

;; * 다른 윈도우로 전환
(global-set-key [(control tab)] 'other-window) 

;; 예 hello.hh와 hello.cc 간 전환위해
(global-set-key [(control x)(control F)] 'ff-find-other-file)
;;(global-set-key [(control c)(F)] 'ff-find-other-file) 


;; * 컴파일
(global-set-key [(control c)(control C)] 'compile-easily)
(global-set-key [(control c)(C)(return)] 'compile-easily)
;; (global-set-key [(control c)(control C)] 'compile)
;; (global-set-key [(control c)(C)(return)] 'compile)
;; (global-set-key [(control c)(control C)] 'compile-according-to-flymake-mode)
;; (global-set-key [(control c)(C)(return)] 'compile-according-to-flymake-mode)

;; * 디버깅
;;(global-set-key [(control c)(control D)] 'gdb-according-to-major-mode-in-new-frame)
(global-set-key [(control c)(D)(return)] 'gdb-according-to-major-mode-in-new-frame)
;;(global-set-key [(control c)(control D)] 'gdb-according-to-major-mode)
;;(global-set-key [(control c)(D)(return)] 'gdb-according-to-major-mode)
;;(global-set-key [(control c)(control D)] 'gdb)
;;(global-set-key [(control c)(D)(return)] 'gdb)
(global-set-key [(control c)(D)(tab)] 'gdb-restore-windows)
;;(global-set-key [(control x)(control D)] 'gdb-restore-windows)


;; * hexa 모드
(global-set-key [(control c)(control X)] 'hexl-mode)
(global-set-key [(control c)(X)(return)] 'hexl-mode)


;; * 태그 자동완성 관련 바인딩
(global-set-key [(meta return)] 'senator-complete-symbol)
(global-set-key [(meta shift return)] 'complete-symbol)
(global-set-key [(control meta return)] 'ebrowse-tags-complete-symbol)

(add-hook 'shell-mode-hook 'ansi-color-for-comint-mode-on)

(set-fontset-font "fontset-default" '(#x1100 . #xffdc) '("Malgun Gothic" . "unicode-bmp"))
(set-fontset-font "fontset-default" '(#xe0bc . #xf66e) '("Malgun Gothic" . "unicode-bmp"))

;;(setq-default indent-tab-mode t)
;;(setq default-tab-width 4)

;; function to reload .emacs 2008.01.24
;; 출처 : http://hermian.tistory.com/195
(defun reload-dotemacs ()
  "Reload .emacs"
  (interactive)
  (load-file "~/.emacs"))

(global-auto-revert-mode 1)

(scroll-bar-mode -1)
(menu-bar-mode 0)

(global-font-lock-mode 1)               ; syntanx highlight
(transient-mark-mode t)                 ; marking highlight
(if (functionp 'global-hi-lock-mode) ; C-x w h 등으로 특정 단어들을 빛내준다
    (global-hi-lock-mode 1)
  (hi-lock-mode 1))
;(global-hl-line-mode 1)                 ; 현재줄을 빛내준다. 이거 좀 불편해서 뺐다.
(setq ring-bell-function (lambda () nil)) ; bell 무시

(line-number-mode 1)                  ; mode line 에 라인수를 표시한다
(column-number-mode 1) ; mode line 에 컬럼을 표시한다(기본이 아니더라)

(setq scroll-step 1)                    ; 윈도스런 스크롤을 위해서..
(setq scroll-conservatively 50)

                                        ; 윈도우처럼, 선택된 regeion 을 DEL 로 지우거나, 다른 글자를 타이핑 할때 즉시 지운다.
(delete-selection-mode 1)

;; function key bindings
(global-set-key (kbd "<f9>") 'compile)
(global-set-key (kbd "<f10>") 'recompile)
(global-set-key (kbd "<f11>") 'dired)
(global-set-key (kbd "<f12>") 'shell)

;;(require 'tabbar)
;;(setq tabbar-buffer-groups-function
;;      (lambda (b) (list "All Buffers")))
;; Don't show *buffers* in the tabbar
;;(setq tabbar-buffer-list-function
;;      (lambda ()
;;        (remove-if
;;       (lambda(buffer)
;;         (find (aref (buffer-name buffer) 0) " *")) (buffer-list))))
;;(tabbar-mode)

;; Org-mode 설정
(add-to-list 'load-path "~/.emacs.d/org/org-mode")
(require 'org)
(add-to-list 'auto-mode-alist '("\\.org$" . org-mode))
(define-key global-map "\C-cl" 'org-store-link)
(define-key global-map "\C-ca" 'org-agenda)
(setq org-log-done t)

(setq gdb-many-windows t)
(add-to-list 'load-path "~/.emacs.d/gdb-snippets")
(load "gdb-snippets")

(add-hook 'c-mode-hook 'turn-on-setnu-mode)       ;; 각 모드에서 setnu를 킴
;;(add-hook 'text-mode-hook 'turn-on-setnu-mode)
(add-hook 'c++-mode-hook 'turn-on-setnu-mode)

(setq-default indent-tabs-mode t)
(setq default-tab-width 8)
(add-hook 'c-mode-hook
         (lambda()
                 (setq c-basic-offset 8)))

;; TODO, BUG 등에 강조표시
(font-lock-add-keywords 'c++-mode
  '(("\\<\\(FIXME\\):" 1 c-nonbreakable-space-face prepend)
    ("\\<\\(TODO\\):" 1 c-nonbreakable-space-face prepend)
    ("\\<\\(BUG\\):" 1 c-nonbreakable-space-face prepend)
    ("\\<\\(NOTE\\):" 1 c-nonbreakable-space-face prepend)))

; backup
(setq make-backup-files nil)

;; 키바인딩
; 기본 셋팅키는 C-x k 입니다
(global-set-key [(control f5)] 'kill-this-buffer)
; proper delete key
;(global-set-key [delete] 'backward-delete-char)
; switches buffers
(global-set-key [?\C-\t] 'bury-buffer)
; C++ compile
(global-set-key [(control f7)] 'compile)

;; 콘솔에서의 백스페이스와 Del키 문제해결
;; backspace
(global-set-key "\C-h" 'delete-backward-char)

;; delete
(global-set-key "\C-[[3~" 'delete-char)

;; 도움말 키를 C-x h 로 바꿈
(global-set-key [?\M-?] 'help-command)


(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(ecb-options-version "2.33beta2")
 '(tabbar-mode t nil (tabbar)))
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 )
