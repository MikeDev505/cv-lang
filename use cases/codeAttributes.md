# Code attributes

Example of code with attributes
``` C# 

void main()
{
  println("This is normal function");
  
  [UnsafeBlock]
  {
    println("This is in unsafe mode function");
  }
    // bloc above is equivalent to:
  using(var context = new UnsafeBlock())
  {
  
  }
  
}

```
