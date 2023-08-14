curl https://raw.githubusercontent.com/ronsavage/SQL/master/sql-2003-2.bnf |
#curl http://savage.net.au/SQL/sql-2003-2.bnf | 
#tr '\r\n\t' ' '  |
# tr '
	' ' ' < /sql-2003-2.bnf  |
sed -r -e '
/^--/,/^--\//M  bcmt
b
:cmt  
s,^,#, 
d
/^--\// {
    b
}
bcmt
'|
 sed  -re ' 
s, *<,\n <,g
s,> *,>\n ,g 
' |
 sed -re '
:Z
/</! s,(\w+) +(\w+),(\1)(\2),g
tZ
' |
 sed -re '
:z
/</,/[^<]*>/ {
s,(.*)[-/:. ]+(\w+),\1\u\2,g
tz
s,(\w+),\u\1,g
}
' |
tr  '\r\n\t' ' ' |
sed -re ' 
s, (\w+), (\1),g
s,(\w+) ,(\1),g
s,\[([\^\[]*)\],!(\1),g
:d3 
/\.\.\./{
s,\{([^\{]*)\} *\.\.\.,+(\1),g
td3
s,<([^<]*)> *\.\.\.,+(\1),g 
td3
}
s,\[,!(,g
s, *(<\w+>) *:: *=,\n\;\;\;\n\n\n\1 ::= ,g
y/\{\<\>\}\]/(\(\)\)\)/
'|
tr -d ' ' |
 sed -re '
:z
s,\!\(\+,*(,g
tz
s,\((\w+)\)\*\(\(\((\w+)\)\(\1\)\)\),((\1%\2)),g
tz
s,\) *(\w+),)(\1),g
tz
s,(\w+) *\(,(\1)(,g
tz
s,\) *([-+!*^]?) *\(,_v6V9v_\1,g
s/\((\w+)\)/\1/g
' -e  '
s,_v6V9v_, >> ,g
s,::=, = ,
s,\|,\n  | ,g
'

