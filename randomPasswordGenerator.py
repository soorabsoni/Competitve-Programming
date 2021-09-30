# -*- coding: utf-8 -*-
"""
Created on Thu Sep 23 12:31:15 2021

@author: NITRO


minimum length 12
must contain lowercase - 1
must contain upper case - 1
must contain atleast 2 numbers - 2
must contain atleast 2 chars out of @#$%^&! - 2
can not have any two same consecutive chars
ss - sS - 11 
can not start with a number
can not start with symbol
"""

import random

a =[
    [chr(65+i) for i in range(26)],
    [chr(97+i) for i in range(26)],
    '@ # $ % ^ & !'.split(),
    [str(i) for i in range(0, 9)],
]
lowerCount = 1
upperCount = 1
numbers = 2
special = 2

last = ''
password = random.choices(a[random.randint(0, 1)])[0]
if password in a[1]: lowerCount -= 1
else: upperCount -= 1

for i in range(11):
    k = password[-1]
    if lowerCount > 0:
        p = random.choices(a[1])[0]
        while k == p:
            p = random.choices(a[1])[0]
        k = p
        lowerCount -= 1
    elif upperCount > 0:
        p = random.choices(a[0])[0]
        while k == p:
            p = random.choices(a[0])[0]
        k = p
        upperCount -= 1
    elif numbers > 0:
        p = random.choices(a[3])[0]
        while k == p:
            p = random.choices(a[3])[0]
        k = p
        numbers -= 1
    elif special > 0:
        p = random.choices(a[2])[0]
        while k == p:
            p = random.choices(a[2])[0]
        k = p
        special -= 1
    else:
        p = random.choices(a[random.randint(0, 3)])[0]
        while k == p:
            p = random.choices(a[random.randint(0, 3)])[0]
        k = p
    password += k

print(password)
        