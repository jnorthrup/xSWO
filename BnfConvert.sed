
/\b\w/! {
	s,^.*$,\n,
}
 
/::=/ bdecl

/</,/[\<]>/      bsymbol

/\[/             bopt

/\{/             breq

b
:cmt  
s,^,#, 
d
/^--\// {
    b
}
bcmt

:decl
N
s,[[:space:]]*([\]}\)>=] *[^.]),\1\n ,g
s,\n, ,g
tdecl
	
:symbol

:opt

:req

:z