// Exercise 7

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_page(string src, string text) {
  //  cout << "I want to find.." << text << endl;
  //cout << "its length is.." << text.length() << endl;
  string stag, etag, result;
  size_t found1, found2, found3;
  stag =  "<" + text + ">";
  etag = "</" + text + ">";
  found1 = src.find(stag);
  found2 = src.find(etag);
  //cout << "found position is .." << found1 << endl;
  found1 = found1 + stag.length();
  found3 = found2 - found1;
  if(found1 != string::npos) {
    result = src.substr(found1,found3); 
    return result;
  }
  else {
    return "No string here..";
  }
}


int main (void) {
	
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 		line.erase();
	}
	// Now page is a string that contains the whole xml page
	
	// Here you need to write something that finds and 
	// extracts location and temperature from the XML
	// data in the string page and stores them in 
	// the strings location and temperature respectively

	location    = find_page(page,"location");
	temperature = find_page(page,"temp_c");
	
	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl; 
}
