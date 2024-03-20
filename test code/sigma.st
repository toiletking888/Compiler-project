{% Sigma.st
 %
 % Compute sum = 1 + 2 + ... + n
 %}

% constant and variable declarations
const n: int := 10
var sum: int
var sndex: int
var c: int := 5
% main statements
sum := 0
for sndex: 1 .. n
  sum := sum + sndex
  if (c > 10) then
  var g: int
  var k: bool := false
  else 
    put c
  end if
end for
put "The result is "
put sum
skip

% loop
sum := 0
sndex := 1
loop
  sum := sum + sndex
  sndex := sndex + 1
  exit when sndex = n
end loop
put "The result is "
put sum

procedure fff33( n:string)
  var c := "hahaha"
  n := c
  begin
    put "wryyyyyyyy"
  end
end fff33
