// Type fundamentals lab - reflection.
// EncoderInterface.dll
//

public interface IEncoder
{
	object Encode(string plainText);
	string Decode(object cipherText);
}
