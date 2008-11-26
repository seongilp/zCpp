// Type fundamentals lab - reflection.
// EncoderAttribute.dll
//
using System;
using System.Reflection;

// TODO: Define the EncoderAttribute custom attribute class.

[AttributeUsage(AttributeTargets.Assembly, AllowMultiple = true)]	
public class EncoderAttribute : System.Attribute
{
	public readonly string Name;
	public readonly string Comment;
	public EncoderAttribute(string text)
	{
		this.Name = text;
	}
}