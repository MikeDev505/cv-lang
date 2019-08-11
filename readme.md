# cv-lang
Fast and elastic language inspired by C, C#, Rust - design concept.

## This is design concept for new language
This document describes the function of the theoretical programming language. Some concepts may not be realized in real language.

Version 0.1

# General topic:
- Why new language? Why not C? Why not C#? Why not Rust?
- cv-lang is Code View Language
- General assumptions for cv-lang
- Simple examples
- General language construct and concept

## Why new language?
C is a fast and universal language (it can be used in embedded programming, programming without an operating system and user programming ..), but in my opinion it is difficult to create a secure application only in C-lang.

C# is simpler, more secure (checking array size, etc.) and has more productivity in development, but is slower than C.

You can use both - create a library in C and use it in a user application written in C #, but why not all in one language?
Generally speaking- a combination of C and C# can look like a one language in which you can create quick key functions (C lib) and quickly create secure business logic (C# user app).

But why not more? What's with MVC (Model View Controller) in the user interface? What's with serialization? What's with templates (like in C++), code generation...

## cv-lang is Code View Language
Simple case: we need a 100 class with 10 properties. 
in C#
``` C#
public class Class1
{
  [Destriptions("some description of property")]
  public string Property1 {get;set;}
  
  [Destriptions("some description of property")]
  public string Property2 {get;set;}
  ...
}
``` 
Really? in the XXI century?
When You creating an application - all the best practices say: "separate the model from the view". We create MVC, MVVM, MVP...

Why not use it in your code?

in cv-lang
``` C#
public class
{
  string Property1 - "some description of property"
  string Property2 - "some description of property"
}
```
The point is: "separate the model/code from the view"
