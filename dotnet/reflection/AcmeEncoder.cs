// Type fundamentals lab - reflection.
// AcmeEncoder.dll
//
using System;
using System.Collections;

// TODO: place the EncoderAttribut attribute on this assembly.
[assembly: Encoder("Test..")]

// NullEncoder
//      An encoder that doesn't actually change
//      the input parameter; instead just returns
//      whatever is passed in to the caller.
//
public class NullEncoder : IEncoder
{
    public object Encode( string plainText )
    {
        return(plainText);
    }

    public string Decode( object cipherText )
    {
        return cipherText.ToString();
    }
}

public class TestEncoder : IEncoder
{
	public object Encode(string plainText)
	{
		return ( plainText );
	}

	public string Decode(object cipherText)
	{
		return cipherText.ToString();
	}
}
