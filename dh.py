#!/usr/bin/python 
import sys 
#usage <python dh.py <g> <mod num> <aVal> <bVal>

#set up arguments
g = int(sys.argv[1])
n = int(sys.argv[2])
aVal = int(sys.argv[3])
bVal = int(sys.argv[4])
foundA = False
foundB = False

for i in range(0, 1000000):
  val = g**i
  if val % n == aVal:
    a = i
    foundA = True
  if val % n == bVal:
    b = i
    foundB = True
  if foundA == True and foundB == True:
    break
  
#find shared secret 
sharedSecretA = aVal**b%n
sharedSecretB = bVal**a%n

if sharedSecretA == sharedSecretB:
  print("a: " + str(a))
  print("b: " + str(b))
  print("Shared secretA: " + str(sharedSecretA))
  print("Shared secretB: " + str(sharedSecretB))
else:
  print("failed")



  
