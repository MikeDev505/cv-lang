# Example

``` C#
void fun1(string s, int i, byte* buffor)
{
  s= "sdfasdfasd sd f";
}

void fun2(string s, int i)
{
  return fun1(s, i, s.GetBufforPointer()) + s;
}

void main()
{
  var s = "sdfsdf";
  fun2(s);
}

```
