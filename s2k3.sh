#!/bin/bash


t=$(mktemp) ;
z=(
$(
[[ -f sql2003.i ]]||./bnf2spirit.sh >sql2003.i ; cp sql2003.i $t 
sed < sql2003.i -rne  '
/^(Non|)ReservedWord *=/,/;;;/M {
/;;;/! {
s,[^\=]*\=,,
s,\W([A-Z][A-Z_0-9]+)\W*, \1 ,g
H
b
}
s,.*,,
x
s,\W*\n*\W*, ,p
}
'|
tr -s '\r\t\ ' '\n' |
sort -fu|
grep -v '^.$'|
grep -v '[\>\)\!\|\=]' |
xargs  echo 
)
)

 
(
set -x 
IFS=\|
#echo ${z[*]}
#exit
sed -re <$t "
/^\w+ *=.+/ {
s,\=,\=\n,g
b
}
:u
s,(\W) ?(${z[*]})(\W|$),\1(\n\2\n)\3,g
t
N
bu
" |sed -re "
s/^(${z[*]})$/str_p("'"&"'")/
t
"|
sed -re "
/\w+ *=/,/;;;/ {
s,(\||=|^) (.)$,\1ch_p('\2'),
}
s,''','\\\'',
"|
sed -nre "

/\w+ *=.*/,/;;;/M  {
:z
N
/;;;/! {
bz
}
s,\n,,g
}
s,(\||>>)(\(*)(ch_p|str_p),\1\2,g
p

"
)
