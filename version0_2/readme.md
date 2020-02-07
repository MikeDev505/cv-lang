# cv-lang
Fast and elastic language inspired by C, C#, Java, Rust - design concept.

## This is design concept for new language
This document describes the function of the theoretical programming language. Language or/and some concepts may not be realized in real language. This is theoretically consideration.

Version 0.1

# General topic:
- Why new language? Why not C? Why not C#? Why not Java Why not Rust?
- cv-lang is Code View Language, running on: microcontrollers, small processor, mobile, desktop and servers processor
- General assumptions for cv-lang
- General language construct and concept
- Simple examples

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

public class Class2
{
  [Destriptions("some description of property")]
  public string Property1 {get;set;}
  
  [Destriptions("some description of property")]
  public string Property2 {get;set;}
  ...
}
...
``` 
Really? in the XXI century?
When You creating an application - all the best practices say: "separate the model from the view". We create MVC, MVVM, MVP...

Why not use it in your code?

in cv-lang
``` C#
class Class1
{
  string Property1 - "some description of property"
  string Property2 - "some description of property"
  ...
}

class Class2
{
  string Property1 - "some description of property"
  string Property2 - "some description of property"
  ...
}
...
```
The point is: "separate the model/code from the view"

## General assumptions for cv-lang
1. Context
    * The team includes experts, senior programmers, junior programmers and non-technical people.
  Everyone has special needs. Experts want to create fast code, younger developers want to create working code, business people need to easily model business logic.
  The language has to provide views and tools needed and understood by each of them
    * There are places in the project where the frames of the technologies used (although they work perfectly well in most cases) are too   rigid. 
  for example: generating UI from code, CRUD operation for administration objects etc.
2. Heterogeneous computing. Should run on: microcontrollers, small processor, mobile, desktop and servers processor
3. Object programming language
4. Flexible syntax depending on the context:
    * strong types by default, but in some context they can be dynamically
    * pointesr may by userd in some contexts 
    * GC can by disabled in some contexts and manual memory management can by used.
5. Depend on JIT/VM.
6. Generic types
7. The code representation depends on the view.
8. Everything is serialized
9. Meta-programming - Code generation before compile, execution in compile time

## General language construct and concept
1. Context:
  * The team includes experts, senior programmers, junior programmers and non-technical people.
  Everyone has special needs. Experts want to create fast code, younger developers want to create working code, business people need to easily model business logic. Language allow special view and 
  * 
  
1. Compilation time code - the user can add code that works during compilation.
2. Everything is serialized - data, code and execution.
    * Data serialization is simple and well known.
    * Serialization of code is a kind of exchange of source code, expression, dynamic library creation, etc.
    * Serialization of execution is a serialization of "Virtual Machine Status"
3. Hardware operations depend on execution context.

## Simple examples
``` C#
public void main()
{
  println("Hello world");
}
```

Object serialization
``` C#
public class Person
{
  string Name {get;set;}
  string Surname {get;set;}
  
  string SomeMethod(string someParam)
  {
    return someParam + " text";
  }
}

public void main()
{
  var person = new Person();
  println(person); 
  
  var stringWithSerialisationofObject = person.Serialize();
  var newInstanceOfPerson = Object.Deserialize(stringWithSerialisationData);
  
  var stringWithSerialisationOfType = Object.Serialize(typeof(Person));
  var newType = Object.Deserialize(stringWithSerialisationOfType);
  var newTypeInstance = Type.Create<Interface/type>(newType, typ); 
  dynamic d = newTypeInstance;
  d.SomeMethode("sdf"); 
}
```
