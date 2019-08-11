# Execution context

Simple dynamic context without gc
``` C#
public void main()
{
  println("some text"); //execute context.println
  
  //create new context, and push on context stack
  using(var newContext = new WithoutGCContext()) //use dynamic contex
  {
    //here all code execute on newContext
    println("Helo from new context"); //newContext.println(...)
    someFunction(); //use newContext
    
    var person = new Person(); //execute newContext.new
  }  
}
```

static contex with memory owner - use in compile time
``` C#
public void main()
{
  println("some text"); //execute context.println
  
  //create new context, and push on context stack
  using(var newContext = new ContextWithMemoryOwner()) //use static context used in compile time
  {
    var person = new Person(); //execute newContext.new - return uniqe<Person>
    var s = someFunction(person); //move responsibility of object to function
    
    print(person); //Compile error - person lost ovner
    print(s); //ok
    
    someFunction(person.Copy());//person now is share and both main and somefunction responsibility for it
    
    //here all code execute on newContext
    println(s); //newContext.println(...)     
    
  }  
}
```

static context with manula memory management - compile time
``` C#
```
public void main()
{
  println("some text"); //execute context.println
  
  //create new context, and push on context stack
  using(var newContext = new ContextWithManualMemoryManagement ()) //use static context used in compile time
  {
    var person = new Person(); //execute newContext.new - return Person*
    var s = someFunction(person); //move responsibility of object to function
    
    print(person); //Compile error - person lost 
    print(s); //ok
    
    //here all code execute on newContext
    println(s); //newContext.println(...)
  }  
}
