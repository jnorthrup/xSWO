#!/bin/bash


t=$(mktemp) ;
z=(
$(
[[ -f sql2003.i ]]||./bnf2spirit.sh >sql2003.i ; cp sql2003.i $t 
sed < sql2003.i -rne  '
/^(Non|)ReservedWord *=/,/;;;/M {
/;;;/! {
s,[^\=]*\=,,
s,\W([A-Z_]+)\W*, \1 ,g
H
b
}
s,.*,,
x
s,\W*\n*\W*, ,p
}
'|
tr -s ' ' '\n' |
sort -fu|
grep -v '^.$'|
grep -v '[\>\)\!\|\=]' |
xargs  echo 
))

 
(
set -x 
IFS=\|
#echo ${z[*]}
#exit
sed -r  <$t "
/=/ s,\=,\=\n,
t

s,(${z[*]})([^A-Za-z_0-9]|$), str_p\(\"\1\") \2,g

"
)
