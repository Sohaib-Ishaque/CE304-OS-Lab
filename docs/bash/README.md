 [Download Latest Book (PDF)](https://github.com/AUT-CEIT/os-lab/releases/download/1/Bash.Programming.pdf)

# Expressions

## `expr`
> Evaluate expressions, evaluates an expression and writes the result on standard output. A blank line below separates increasing precedence groups. 
[ReadMore](http://ss64.com/bash/expr.html)

**Syntax**

```bash
    expr expression
    expr option
```

**Expressions**

    ARG1 | ARG2               ARG1 if it is neither null nor 0, otherwise ARG2 
    ARG1 & ARG2               ARG1 if neither argument is null or 0, otherwise 0 
    ARG1 < ARG2               ARG1 is less than ARG2 
    ARG1 <= ARG2              ARG1 is less than or equal to ARG2 
    ARG1 = ARG2               ARG1 is equal to ARG2 
    ARG1 != ARG2              ARG1 is unequal to ARG2 
    ARG1 >= ARG2              ARG1 is greater than or equal to ARG2 
    ARG1 > ARG2               ARG1 is greater than ARG2 
    ARG1 + ARG2               Arithmetic sum of ARG1 and ARG2 
    ARG1 - ARG2               Arithmetic difference of ARG1 and ARG2 
    ARG1 * ARG2               Arithmetic product of ARG1 and ARG2 
    ARG1 / ARG2               Arithmetic quotient of ARG1 divided by ARG2 
    ARG1 % ARG2               Arithmetic remainder of ARG1 divided by ARG2 
    STRING : REGEXP           Anchored pattern match of REGEXP in STRING 
    match STRING REGEXP       Same as STRING : REGEXP 
    substr STRING POS LENGTH  Substring of STRING, POS counted from 1 
    index STRING CHARS        Index in STRING where any CHARS is found, or 0 
    length STRING             Length of STRING 

**Examples**

```bash
# Adding numbers
$ expr 5 + 2
7

# When multiplying the * has to be escaped
$ expr 5 \* 3
15

# Increment a variable (arithmetic expansion)
$ demo=1
$ demo=`expr $demo + 1`
$ echo $demo
2
$ demo=`expr $demo + 1`
$ echo $demo
3

$ expr index abcdef cz
3
```


----------


## `let`
> Perform arithmetic on shell variables.
Each expression is an arithmetic expression to be evaluated. If the last expression evaluates to 0, let returns 1; otherwise 0 is returned. 
[ReadMore](http://ss64.com/bash/let.html)

let is very similar to (( - the only difference being let is a builtin (simple command), and (( is a compound command.

**Examples**

```bash
a=`expr 3 \* 3`
let "a=3*3"
((3*3))
```


# Shell Expansion
> Expansion is performed on the command line after it has been split into `tokens`. [ReadMore](http://ss64.com/bash/syntax-expand.html)

The order of expansions is:
- brace expansion
- tilde expansion
- parameter, variable,  arithmetic expansion, command 
- word splitting, filename expansion
- quote removal

## Command Substitution
> Command substitution allows the output of a command to replace the command itself. 

Command substitution occurs when a command is enclosed as follows:
 `$(command)` or \`command\`


----------


## Brace Expansion
> Brace expansion is a mechanism by which arbitrary strings can be generated. This mechanism is similar to filename expansion (see section Filename Expansion), but the file names generated need not exist. Patterns to be brace expanded take the form of an optional preamble, followed by a series of comma-separated strings between a pair of braces, followed by an optional postscript. The preamble is prefixed to each string contained within the braces, and the postscript is then appended to each resulting string, expanding left to right.

Brace expansions can be nested. The results of each expanded string are not sorted; left to right order is preserved. For example,
```bash
bash$ echo a{d,c,b}e
ade ace abe
```

Brace expansion is performed before any other expansions, and any characters special to other expansions are preserved in the result. It is strictly textual. Bash does not apply any syntactic interpretation to the context of the expansion or the text between the braces. To avoid conflicts with parameter expansion, the string `${' is not considered eligible for brace expansion.

A correctly-formed brace expansion must contain unquoted opening and closing braces, and at least one unquoted comma. Any incorrectly formed brace expansion is left unchanged.

This construct is most useful when the strings involved have a long common prefix, such as a long file path.

*Examples*

```bash
$ mkdir /usr/local/src/bash/{old,new,dist}

$ mv app/ss64/alpha.py app/ss64/alphabeta.py

## Can be
$ mv app/ss64/{alpha,alphabeta}.py

## Or even
$ mv app/ss64/alpha{,beta}.py
```


----------


## Tilde Expansion

> If a word begins with an unquoted tilde character (`~'), all of the characters up to the first unquoted slash (or all characters, if there is no unquoted slash) are considered a tilde-prefix. If none of the characters in the tilde-prefix are quoted, the characters in the tilde-prefix following the tilde are treated as a possible login name. If this login name is the null string, the tilde is replaced with the value of the HOME shell variable. If HOME is unset, the home directory of the user executing the shell is substituted instead. Otherwise, the tilde-prefix is replaced with the home directory associated with the specified login name.

If the tilde-prefix is ~+, the value of the shell variable PWD replaces the tilde-prefix. If the tilde-prefix is ~- the value of the shell variable OLDPWD, if it is set, is substituted.

*Examples*

```bash
# The value of $HOME 
bash$ echo ~

# The subdirectory foo of the home directory of the user fred 
bash$ echo ~/foo
bash$ echo $HOME/foo
bash$ echo ~fred/foo 

# Paths relative to Current Directory
bash$ echo ~+/foo
bash$ echo $PWD/foo 
bash$ echo ~-/foo

```

----------


## Shell Parameter Expansion

> The $ character introduces parameter expansion, command substitution, or arithmetic expansion. The parameter name or symbol to be expanded can be enclosed in braces, which are optional but serve to protect the variable to be expanded from characters immediately following it which could be interpreted as part of the name.

`${parameter:-word} `
> If parameter is unset or null, the expansion of **word** is substituted. 

`${parameter:=word}`
If parameter is unset or null, the expansion of word is **assigned** to parameter.The value of parameter is then substituted.   
> *Note*: Positional parameters and special parameters can not be assigned to in this way.

`${parameter:?word}`
If parameter is null or unset, the expansion of word (or a message to that effect if word is not present) is written to the **standard error** and the shell, if it is not interactive, **exits**.

`${parameter:+word}`
If parameter is null or unset, **nothing** is substituted, otherwise the expansion of word is substituted.

`${parameter:offset} `
`${parameter:offset:length}`
Expands to up to length characters of parameter starting at the character specified by offset. If length is omitted, expands to the sub-string of parameter starting at the character specified by offset. length and offset are arithmetic expressions. This is referred to as Sub-string Expansion. 

### String Pattern Matching

> The word is expanded to produce a pattern just as in filename expansion. If the pattern matches the beginning of the expanded value of parameter, then the result of the expansion is the expanded value of parameter with the shortest matching pattern (the '#' case) or the longest matching pattern (the '##' case) deleted.

**String Operations**

Operation     | Description
--------------|---------------
 #            | Removes minimal matching prefixes
 ##           | Removes maximal matching prefixes
 %            | Removes minimal matching suffixes
 %%           | Removes maximal matching suffixes

**Examples**

```bash
$ SOURCEFILE=/usr/local/src/prog.c

$ echo ${SOURCEFILE#/*/}
local/src/prog.c

$ echo ${SOURCEFILE##/*/}
prog.c

$ echo ${SOURCEFILE%/*}
/usr/local/src

$ echo ${SOURCEFILE%%/*}
```


----------


## Pattern Matching
> Any character that appears in a pattern, other than the special pattern characters described below, matches itself. The NUL character can not occur in a pattern. The special pattern characters must be quoted if they are to be matched literally.

*The special pattern characters have the following meanings:*

**\*** 
Matches any string, including the null string. 

**?** 
Matches any single character. 

**Following Patterns need `extglob` enabled**

**?(pattern-list)** 
Matches zero or one occurrence of the given patterns. 

**\*(pattern-list)** 
Matches zero or more occurrences of the given patterns. 

**+(pattern-list)** 
Matches one or more occurrences of the given patterns. 

**@(pattern-list)** 
Matches exactly one of the given patterns. 

**!(pattern-list)** 
Matches anything except one of the given patterns.

**Examples**
```bash
~/foobar> shopt extglob
extglob         off
~/foobar> ls
abar  afoo  bbar  bfoo
~/foobar> ls !(b*)
-bash: !: event not found
~/foobar> shopt -s extglob  #Enables extglob
~/foobar> ls !(b*)
abar  afoo
~/foobar> ls !(a*)
bbar  bfoo
~/foobar> ls !(*foo)
abar  bbar
```

----------

# Control statements

## `if`
> Conditionally perform a command. [ReadMore](http://ss64.com/bash/if.html)

**Syntax**
```bash
    if test-commands; then
	       consequent-commands;
       elif more-test-commands; then 
	       more-consequents;
       else
	       alternate-consequents;
    fi
```

The test-commands list is executed, and if its return status is zero, the consequent-commands list is executed.

If test-commands returns a non-zero status, each `elif` list is executed in turn, and if its exit status is zero, the corresponding more-consequents is executed and the command completes.

If else alternate-consequents' is present, and the final command in the final if or elif clause has a non-zero exit status, then alternate-consequents is executed.

**Example**

```bash
if grep "UNIX" myfile >/dev/null ;then
 echo UNIX occurs in myfile
elif grep “DOS” myfile > /dev/null ;then
 echo DOS appears in myfile not UNIX
else
 echo nobody is here in myfile
fi
```

For simple comparisons, a more concise option is to use a conditional operator instead of IF.  For example: 
```bash
[ "$var" = "snark" ] && echo "found snark" 
```
Instead of:
```bash
if [ "$var" = "snark" ] ;then 
	echo "found snark" 
fi
```

The return status is the exit status of the last command executed, or zero if no condition tested true. if is a bash builtin command.

----------


## `test` or `[`
> Evaluate a conditional expression `expression`. [ReadMore](http://ss64.com/bash/test.html)

**Syntax**
```bash
     test expression
     [ expression
```

**Options**
Each operator and operand must be a separate argument. When the [ form is used, the last argument to the command must be a ]. Expressions can be combined using the following operators, listed in decreasing order of precedence.

**! expr**
True if expr is false.

**( expr )**
Returns the value of expr. This can be used to override the normal precedence of operators. 

**expr1 -a expr2**
True if both expr1 and expr2 are true.

**expr1 -o expr2**
True if either expr1 or expr2 is true.


----------

## `for` Loop
> for loops allow the repetition of a command for a specific set of values. [Read More](http://ss64.com/bash/for.html)

**Syntax**

```bash
# 1
for var in value1 value2 ... ; do
	command_set
done

# 2
for var in {START..END} ; do
	command_set
done

# 3
for (( expr1; expr2; expr3 )) ; do
 command_set
done

# 4
for var in {START..END..INCREMENT} ; do
	command_set
done
```

**Examples**

```bash
# 1- Listing all files in a directory.
for i in * ;do
	if [ -d "$i" ] ;then
		echo "$i"
	fi
done

# 2
for i in {1..5} ; do
	echo "Welcome $i times"
done

# 3
for i in {0..10..2} ;do
	echo "Welcome $i times"
done

# 4
for (( c=1; c<=5; c++ )) ;do
	echo "Welcome $c times"
done

# 5
for (( ; ; )) ;do
echo "infinite loops [ hit CTRL+C to stop]"
done

# 6- Count executables in directory
count=0
for i in *; do
	if test –x $i ; then
	 count=`expr $count + 1`
	fi
done
echo Total of $count files executable

```

----------

## `while` Loop
> Execute consequent-commands as long as test-commands has an exit status of zero. [Read More](http://ss64.com/bash/while.html)

**Syntax**
```bash
while test-command ;do
	 commands
done
```

**Example**
```bash
# The value of i is tested in the while to see if it is less than or equal to 100.

i=1
sum=0
while [ $i -le 100 ] ;do
 sum=`expr $sum + $i`
 i=`expr $i + 1`
done
echo The sum is $sum.
```

----------

## `until` Loop
> Execute consequent-commands as long as test-commands has an exit status which is not zero. [Read More](http://ss64.com/bash/until.html)

**Syntax**
```bash
until test-command; do
	commands
done
```

**Example**
```bash
number=0
until [ $number -ge 10 ]; do
	echo "Number = $number"
	number=$((number + 1))
done
```

## `case`
> Conditionally perform a command, case will selectively execute the command-list corresponding to the first pattern that matches word.  [Read More](http://ss64.com/bash/case.html)

**Syntax**
```bash
case word in
 patterns ) 
	 commands
 ;;
 pattern ) 
	 command
esac
```

**Example**
```bash
echo -n "Type a digit or a letter > "
read character

case $character in
 [a-z] | [A-Z] ) echo "You typed the letter $character" ;;
 [0-9] ) echo "You typed the digit $character" ;;
 * ) echo "You did not type a letter or a digit"
esac
```

## `break` and `continue`

**Examples for `break`**

```bash

# 1
a=0
while [ $a -lt 10 ] ;do
	echo $a
	[ $a -eq 5 ] && break
done
a=`expr $a + 1`

# 2
for var1 in 1 2 3 ;do
	for var2 in 0 5 ;do
		 if [ $var1 -eq 2 -a $var2 -eq 0 ] ;then
			 break 2
		 else
			 echo "$var1 $var2"
		 fi
	done
done
```

**Examples for `continue`**

```bash
# 1
NUMS="1 2 3 4 5 6 7" 
for NUM in $NUMS ;do
	 Q=`expr $NUM % 2`
	 if [ $Q -eq 0 ] ;then
		 echo "Number is an even number!!"
		 continue
	 fi
	echo "Found odd number"
done

```


# Brackets

##  Group commands in a sub/current  shell
> Grouping a (list of commands) in parenthesis causes them to be executed as if they were a single unit. When commands are grouped, redirections can be applied to the entire command list. For example, the output of all the commands in the list can be redirected to a single stream. [ReadMore](http://ss64.com/bash/syntax-brackets.html)

Placing a list of commands between curly braces causes the list to be executed in the current shell context. No subshell is created. The semicolon (or newline) following list is required.
 **Syntax**

    (commands)

 Placing a list of commands between parentheses causes a subshell to be created, and each of the commands in list to be executed in that subshell. Since the list is executed in a subshell, variable assignments do not remain in effect after the subshell completes.

 **Syntax**
 
       {commands}


**Example**

```bash
(echo a;echo b)>file
```

## Return a binary result of expression
>Return a status of 0 or 1 depending on the evaluation of the conditional expression. Word splitting and filename expansion are not performed on the words between the `[[` and `]]` tilde expansion, parameter and variable expansion, arithmetic expansion, command substitution, process substitution, and quote removal are performed. 

 **Syntax**

       [[ expression ]] 


When the `==` and `!=` operators are used, pattern matching will be done on the - string to the right of the operator.

The return value is 0 if the string matches or does not match the pattern, respectively, and 1 otherwise. 

Any part of the pattern can be quoted to force it to be matched as a string. 

**Example**

```bash
[[ $age>30 && $age<60 ]] && echo "FOO"
```

## Arithmetic expansion
> Arithmetic expansion allows the evaluation of an arithmetic expression and the substitution of the result.
> The expression is treated as if it were within double quotes, but a double quote inside the parentheses is not treated specially. All tokens in the expression undergo parameter expansion, command substitution, and quote removal. Arithmetic substitutions can be nested.

**Syntax**

	$(( expression ))

**Example**

```bash
((a=3*3))
```


----------
Prepared By Pooya Parsa <pooya@pi0.ir>   
Amirkabir university of technology   
Last Modified: Wed, Oct 26, 2016   



