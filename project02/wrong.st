% Hello World Example 
  
% Print text to the console

	
var a:array 1 .. 10 of int
var b:bool := true
var c:int := 6

%c := a[15]

%var c:int := 5
%var a: array 1 .. 7 of int

{%for decreasing a:1 .. 5
  begin
  end
end for%}

function t ( i:int, j:int) : bool
  result false
end t 

%b := t(20)

%b := t()

put ("END")
