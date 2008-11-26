// Type fundamentals lab - reflection.
// This file contains the EncoderAttribute test application.

using System;
using System.Reflection;
using System.Collections;

class App
{
    static void Main(string[] args)
    {
        // TODO: Load the AcmeEncoder assembly.
		Assembly asm	= Assembly.LoadFrom("AcmeEncoder.dll");
		Type attrType	= typeof(EncoderAttribute);
		if ( asm.IsDefined(attrType, false) )
			Console.WriteLine("Assembly has an attribute");

		object[] attrs = asm.GetCustomAttributes(attrType, false);
		
		// TODO: Extract any EncodeAttributes that have been applied
        //       to the assembly.

        // TODO: Iterate through the list of EncoderAttribute attributes
        //       (if any) that were just returned, exercising any encoders
        //       that are found.
		foreach ( EncoderAttribute eattr in attrs )
		{
			Console.WriteLine("Text: " + eattr.Name);
			Console.WriteLine("Found Encoder: {0}" , eattr.TypeId);
		}
    }
}
