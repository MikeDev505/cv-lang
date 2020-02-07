# Executing in Host-microcontroller 

``` C#
string someFunction(string param)
{
}

//host
void main()
{
  using(var context = new ArmContext())
  {
    //all execution on microcontroller
    someFunction("text");
  }

}
```
