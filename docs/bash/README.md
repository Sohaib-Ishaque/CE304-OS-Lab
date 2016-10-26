<p>Prepared By Pooya Parsa <a href="mailto:pooya@pi0.ir">pooya@pi0.ir</a><br>
Amirkabir university of technology<br>
Last Modified: Wed, Oct 26, 2016</p>
<h1 id="expressions">Expressions</h1>
<h2 id="expr"><code>expr</code></h2>
<blockquote>
<p>Evaluate expressions, evaluates an expression and writes the result on standard output. A blank line below separates increasing precedence groups.<br>
<a href="http://ss64.com/bash/expr.html">ReadMore</a></p>
</blockquote>
<p><strong>Syntax</strong></p>
<pre class=" language-bash"><code class="prism  language-bash">    <span class="token function">expr</span> expression
    <span class="token function">expr</span> option
</code></pre>
<p><strong>Expressions</strong></p>
<pre><code>ARG1 | ARG2               ARG1 if it is neither null nor 0, otherwise ARG2 
ARG1 &amp; ARG2               ARG1 if neither argument is null or 0, otherwise 0 
ARG1 &lt; ARG2               ARG1 is less than ARG2 
ARG1 &lt;= ARG2              ARG1 is less than or equal to ARG2 
ARG1 = ARG2               ARG1 is equal to ARG2 
ARG1 != ARG2              ARG1 is unequal to ARG2 
ARG1 &gt;= ARG2              ARG1 is greater than or equal to ARG2 
ARG1 &gt; ARG2               ARG1 is greater than ARG2 
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
</code></pre>
<p><strong>Examples</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token comment" spellcheck="true"># Adding numbers</span>
$ <span class="token function">expr</span> 5 + 2
7

<span class="token comment" spellcheck="true"># When multiplying the * has to be escaped</span>
$ <span class="token function">expr</span> 5 \* 3
15

<span class="token comment" spellcheck="true"># Increment a variable (arithmetic expansion)</span>
$ demo<span class="token operator">=</span>1
$ demo<span class="token operator">=</span><span class="token variable"><span class="token variable">`</span><span class="token function">expr</span> $demo + 1<span class="token variable">`</span></span>
$ <span class="token keyword">echo</span> <span class="token variable">$demo</span>
2
$ demo<span class="token operator">=</span><span class="token variable"><span class="token variable">`</span><span class="token function">expr</span> $demo + 1<span class="token variable">`</span></span>
$ <span class="token keyword">echo</span> <span class="token variable">$demo</span>
3

$ <span class="token function">expr</span> index abcdef cz
3
</code></pre>
<hr>
<h2 id="let"><code>let</code></h2>
<blockquote>
<p>Perform arithmetic on shell variables.<br>
Each expression is an arithmetic expression to be evaluated. If the last expression evaluates to 0, let returns 1; otherwise 0 is returned.<br>
<a href="http://ss64.com/bash/let.html">ReadMore</a></p>
</blockquote>
<p>let is very similar to (( - the only difference being let is a builtin (simple command), and (( is a compound command.</p>
<p><strong>Examples</strong></p>
<pre class=" language-bash"><code class="prism  language-bash">a<span class="token operator">=</span><span class="token variable"><span class="token variable">`</span><span class="token function">expr</span> 3 \* 3<span class="token variable">`</span></span>
<span class="token keyword">let</span> <span class="token string">"a=3*3"</span>
</code></pre>
<h1 id="shell-expansion">Shell Expansion</h1>
<blockquote>
<p>Expansion is performed on the command line after it has been split into <code>tokens</code>. <a href="http://ss64.com/bash/syntax-expand.html">ReadMore</a></p>
</blockquote>
<p>The order of expansions is:</p>
<ul>
<li>brace expansion</li>
<li>tilde expansion</li>
<li>parameter, variable,  arithmetic expansion, command</li>
<li>word splitting, filename expansion</li>
<li>quote removal</li>
</ul>
<h2 id="command-substitution">Command Substitution</h2>
<blockquote>
<p>Command substitution allows the output of a command to replace the command itself.</p>
</blockquote>
<p>Command substitution occurs when a command is enclosed as follows:<br>
<code>$(command)</code> or `command`</p>
<hr>
<h2 id="brace-expansion">Brace Expansion</h2>
<blockquote>
<p>Brace expansion is a mechanism by which arbitrary strings can be generated. This mechanism is similar to filename expansion (see section Filename Expansion), but the file names generated need not exist. Patterns to be brace expanded take the form of an optional preamble, followed by a series of comma-separated strings between a pair of braces, followed by an optional postscript. The preamble is prefixed to each string contained within the braces, and the postscript is then appended to each resulting string, expanding left to right.</p>
</blockquote>
<p>Brace expansions can be nested. The results of each expanded string are not sorted; left to right order is preserved. For example,</p>
<pre class=" language-bash"><code class="prism  language-bash">bash$ <span class="token keyword">echo</span> a<span class="token punctuation">{</span>d,c,b<span class="token punctuation">}</span>e
ade ace abe
</code></pre>
<p>Brace expansion is performed before any other expansions, and any characters special to other expansions are preserved in the result. It is strictly textual. Bash does not apply any syntactic interpretation to the context of the expansion or the text between the braces. To avoid conflicts with parameter expansion, the string `${’ is not considered eligible for brace expansion.</p>
<p>A correctly-formed brace expansion must contain unquoted opening and closing braces, and at least one unquoted comma. Any incorrectly formed brace expansion is left unchanged.</p>
<p>This construct is most useful when the strings involved have a long common prefix, such as a long file path.</p>
<p><em>Examples</em></p>
<pre class=" language-bash"><code class="prism  language-bash">$ <span class="token function">mkdir</span> /usr/local/src/bash/<span class="token punctuation">{</span>old,new,dist<span class="token punctuation">}</span>

$ <span class="token function">mv</span> app/ss64/alpha.py app/ss64/alphabeta.py

<span class="token comment" spellcheck="true">## Can be</span>
$ <span class="token function">mv</span> app/ss64/<span class="token punctuation">{</span>alpha,alphabeta<span class="token punctuation">}</span>.py

<span class="token comment" spellcheck="true">## Or even</span>
$ <span class="token function">mv</span> app/ss64/alpha<span class="token punctuation">{</span>,beta<span class="token punctuation">}</span>.py
</code></pre>
<hr>
<h2 id="tilde-expansion">Tilde Expansion</h2>
<blockquote>
<p>If a word begins with an unquoted tilde character (`~’), all of the characters up to the first unquoted slash (or all characters, if there is no unquoted slash) are considered a tilde-prefix. If none of the characters in the tilde-prefix are quoted, the characters in the tilde-prefix following the tilde are treated as a possible login name. If this login name is the null string, the tilde is replaced with the value of the HOME shell variable. If HOME is unset, the home directory of the user executing the shell is substituted instead. Otherwise, the tilde-prefix is replaced with the home directory associated with the specified login name.</p>
</blockquote>
<p>If the tilde-prefix is ~+, the value of the shell variable PWD replaces the tilde-prefix. If the tilde-prefix is ~- the value of the shell variable OLDPWD, if it is set, is substituted.</p>
<p><em>Examples</em></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token comment" spellcheck="true"># The value of $HOME </span>
bash$ <span class="token keyword">echo</span> ~

<span class="token comment" spellcheck="true"># The subdirectory foo of the home directory of the user fred </span>
bash$ <span class="token keyword">echo</span> ~/foo
bash$ <span class="token keyword">echo</span> <span class="token variable">$HOME</span>/foo
bash$ <span class="token keyword">echo</span> ~fred/foo 

<span class="token comment" spellcheck="true"># Paths relative to Current Directory</span>
bash$ <span class="token keyword">echo</span> ~+/foo
bash$ <span class="token keyword">echo</span> <span class="token variable">$PWD</span>/foo 
bash$ <span class="token keyword">echo</span> ~-/foo

</code></pre>
<hr>
<h2 id="shell-parameter-expansion">Shell Parameter Expansion</h2>
<blockquote>
<p>The $ character introduces parameter expansion, command substitution, or arithmetic expansion. The parameter name or symbol to be expanded can be enclosed in braces, which are optional but serve to protect the variable to be expanded from characters immediately following it which could be interpreted as part of the name.</p>
</blockquote>
<p><code>${parameter:-word}</code></p>
<blockquote>
<p>If parameter is unset or null, the expansion of <strong>word</strong> is substituted.</p>
</blockquote>
<p><code>${parameter:=word}</code><br>
If parameter is unset or null, the expansion of word is <strong>assigned</strong> to parameter.The value of parameter is then substituted.</p>
<blockquote>
<p><em>Note</em>: Positional parameters and special parameters can not be assigned to in this way.</p>
</blockquote>
<p><code>${parameter:?word}</code><br>
If parameter is null or unset, the expansion of word (or a message to that effect if word is not present) is written to the <strong>standard error</strong> and the shell, if it is not interactive, <strong>exits</strong>.</p>
<p><code>${parameter:+word}</code><br>
If parameter is null or unset, <strong>nothing</strong> is substituted, otherwise the expansion of word is substituted.</p>
<p><code>${parameter:offset}</code><br>
<code>${parameter:offset:length}</code><br>
Expands to up to length characters of parameter starting at the character specified by offset. If length is omitted, expands to the sub-string of parameter starting at the character specified by offset. length and offset are arithmetic expressions. This is referred to as Sub-string Expansion.</p>
<h3 id="string-pattern-matching">String Pattern Matching</h3>
<blockquote>
<p>The word is expanded to produce a pattern just as in filename expansion. If the pattern matches the beginning of the expanded value of parameter, then the result of the expansion is the expanded value of parameter with the shortest matching pattern (the ‘#’ case) or the longest matching pattern (the ‘##’ case) deleted.</p>
</blockquote>
<p><strong>String Operations</strong></p>
<table>
<thead>
<tr>
<th>Operation</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr>
<td>#</td>
<td>Removes minimal matching prefixes</td>
</tr>
<tr>
<td>##</td>
<td>Removes maximal matching prefixes</td>
</tr>
<tr>
<td>%</td>
<td>Removes minimal matching suffixes</td>
</tr>
<tr>
<td>%%</td>
<td>Removes maximal matching suffixes</td>
</tr>
</tbody>
</table>
<p><strong>Examples</strong></p>
<pre class=" language-bash"><code class="prism  language-bash">$ SOURCEFILE<span class="token operator">=</span>/usr/local/src/prog.c

$ <span class="token keyword">echo</span> $<span class="token punctuation">{</span>SOURCEFILE<span class="token comment" spellcheck="true">#/*/}</span>
local/src/prog.c

$ <span class="token keyword">echo</span> $<span class="token punctuation">{</span>SOURCEFILE<span class="token comment" spellcheck="true">##/*/}</span>
prog.c

$ <span class="token keyword">echo</span> <span class="token variable">${SOURCEFILE%/*}</span>
/usr/local/src

$ <span class="token keyword">echo</span> <span class="token variable">${SOURCEFILE%%/*}</span>
</code></pre>
<hr>
<h2 id="pattern-matching">Pattern Matching</h2>
<blockquote>
<p>Any character that appears in a pattern, other than the special pattern characters described below, matches itself. The NUL character can not occur in a pattern. The special pattern characters must be quoted if they are to be matched literally.</p>
</blockquote>
<p><em>The special pattern characters have the following meanings:</em></p>
<p><strong>*</strong><br>
Matches any string, including the null string.</p>
<p><strong>?</strong><br>
Matches any single character.</p>
<p><strong>Following Patterns need <code>extglob</code> enabled</strong></p>
<p><strong>?(pattern-list)</strong><br>
Matches zero or one occurrence of the given patterns.</p>
<p><strong>*(pattern-list)</strong><br>
Matches zero or more occurrences of the given patterns.</p>
<p><strong>+(pattern-list)</strong><br>
Matches one or more occurrences of the given patterns.</p>
<p><strong>@(pattern-list)</strong><br>
Matches exactly one of the given patterns.</p>
<p><strong>!(pattern-list)</strong><br>
Matches anything except one of the given patterns.</p>
<p><strong>Examples</strong></p>
<pre class=" language-bash"><code class="prism  language-bash">~/foobar<span class="token operator">&gt;</span> <span class="token function">shopt</span> extglob
extglob         off
~/foobar<span class="token operator">&gt;</span> <span class="token function">ls</span>
abar  afoo  bbar  bfoo
~/foobar<span class="token operator">&gt;</span> <span class="token function">ls</span> <span class="token operator">!</span><span class="token punctuation">(</span>b*<span class="token punctuation">)</span>
-bash: <span class="token operator">!</span>: event not found
~/foobar<span class="token operator">&gt;</span> <span class="token function">shopt</span> -s extglob  <span class="token comment" spellcheck="true">#Enables extglob</span>
~/foobar<span class="token operator">&gt;</span> <span class="token function">ls</span> <span class="token operator">!</span><span class="token punctuation">(</span>b*<span class="token punctuation">)</span>
abar  afoo
~/foobar<span class="token operator">&gt;</span> <span class="token function">ls</span> <span class="token operator">!</span><span class="token punctuation">(</span>a*<span class="token punctuation">)</span>
bbar  bfoo
~/foobar<span class="token operator">&gt;</span> <span class="token function">ls</span> <span class="token operator">!</span><span class="token punctuation">(</span>*foo<span class="token punctuation">)</span>
abar  bbar
</code></pre>
<hr>
<h1 id="control-statements">Control statements</h1>
<h2 id="if"><code>if</code></h2>
<blockquote>
<p>Conditionally perform a command. <a href="http://ss64.com/bash/if.html">ReadMore</a></p>
</blockquote>
<p><strong>Syntax</strong></p>
<pre class=" language-bash"><code class="prism  language-bash">    <span class="token keyword">if</span> test-commands<span class="token punctuation">;</span> <span class="token keyword">then</span>
	       consequent-commands<span class="token punctuation">;</span>
       <span class="token keyword">elif</span> more-test-commands<span class="token punctuation">;</span> <span class="token keyword">then</span> 
	       more-consequents<span class="token punctuation">;</span>
       <span class="token keyword">else</span>
	       alternate-consequents<span class="token punctuation">;</span>
    <span class="token keyword">fi</span>
</code></pre>
<p>The test-commands list is executed, and if its return status is zero, the consequent-commands list is executed.</p>
<p>If test-commands returns a non-zero status, each <code>elif</code> list is executed in turn, and if its exit status is zero, the corresponding more-consequents is executed and the command completes.</p>
<p>If else alternate-consequents’ is present, and the final command in the final if or elif clause has a non-zero exit status, then alternate-consequents is executed.</p>
<p><strong>Example</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token keyword">if</span> <span class="token function">grep</span> <span class="token string">"UNIX"</span> myfile <span class="token operator">&gt;</span>/dev/null <span class="token punctuation">;</span><span class="token keyword">then</span>
 <span class="token keyword">echo</span> UNIX occurs <span class="token keyword">in</span> myfile
<span class="token keyword">elif</span> <span class="token function">grep</span> “DOS” myfile <span class="token operator">&gt;</span> /dev/null <span class="token punctuation">;</span><span class="token keyword">then</span>
 <span class="token keyword">echo</span> DOS appears <span class="token keyword">in</span> myfile not UNIX
<span class="token keyword">else</span>
 <span class="token keyword">echo</span> nobody is here <span class="token keyword">in</span> myfile
<span class="token keyword">fi</span>
</code></pre>
<p>For simple comparisons, a more concise option is to use a conditional operator instead of IF.  For example:</p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token punctuation">[</span> <span class="token string">"<span class="token variable">$var</span>"</span> <span class="token operator">=</span> <span class="token string">"snark"</span> <span class="token punctuation">]</span> <span class="token operator">&amp;&amp;</span> <span class="token keyword">echo</span> <span class="token string">"found snark"</span> 
</code></pre>
<p>Instead of:</p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token keyword">if</span> <span class="token punctuation">[</span> <span class="token string">"<span class="token variable">$var</span>"</span> <span class="token operator">=</span> <span class="token string">"snark"</span> <span class="token punctuation">]</span> <span class="token punctuation">;</span><span class="token keyword">then</span> 
	<span class="token keyword">echo</span> <span class="token string">"found snark"</span> 
<span class="token keyword">fi</span>
</code></pre>
<p>The return status is the exit status of the last command executed, or zero if no condition tested true. if is a bash builtin command.</p>
<hr>
<h2 id="test-or-"><code>test</code> or <code>[</code></h2>
<blockquote>
<p>Evaluate a conditional expression <code>expression</code>. <a href="http://ss64.com/bash/test.html">ReadMore</a></p>
</blockquote>
<p><strong>Syntax</strong></p>
<pre class=" language-bash"><code class="prism  language-bash">     <span class="token function">test</span> expression
     <span class="token punctuation">[</span> expression
</code></pre>
<p><strong>Options</strong><br>
Each operator and operand must be a separate argument. When the [ form is used, the last argument to the command must be a ]. Expressions can be combined using the following operators, listed in decreasing order of precedence.</p>
<p><strong>! expr</strong><br>
True if expr is false.</p>
<p><strong>( expr )</strong><br>
Returns the value of expr. This can be used to override the normal precedence of operators.</p>
<p><strong>expr1 -a expr2</strong><br>
True if both expr1 and expr2 are true.</p>
<p><strong>expr1 -o expr2</strong><br>
True if either expr1 or expr2 is true.</p>
<hr>
<h2 id="for-loop"><code>for</code> Loop</h2>
<blockquote>
<p>for loops allow the repetition of a command for a specific set of values. <a href="http://ss64.com/bash/for.html">Read More</a></p>
</blockquote>
<p><strong>Syntax</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token comment" spellcheck="true"># 1</span>
<span class="token keyword">for</span> var <span class="token keyword">in</span> value1 value2 <span class="token punctuation">..</span>. <span class="token punctuation">;</span> <span class="token keyword">do</span>
	command_set
<span class="token keyword">done</span>

<span class="token comment" spellcheck="true"># 2</span>
<span class="token keyword">for</span> var <span class="token keyword">in</span> <span class="token punctuation">{</span>START<span class="token punctuation">..</span>END<span class="token punctuation">}</span> <span class="token punctuation">;</span> <span class="token keyword">do</span>
	command_set
<span class="token keyword">done</span>

<span class="token comment" spellcheck="true"># 3</span>
<span class="token keyword">for</span> <span class="token variable"><span class="token punctuation">((</span> expr1<span class="token punctuation">;</span> expr2<span class="token punctuation">;</span> expr3 <span class="token punctuation">))</span></span> <span class="token punctuation">;</span> <span class="token keyword">do</span>
 command_set
<span class="token keyword">done</span>

<span class="token comment" spellcheck="true"># 4</span>
<span class="token keyword">for</span> var <span class="token keyword">in</span> <span class="token punctuation">{</span>START<span class="token punctuation">..</span>END<span class="token punctuation">..</span>INCREMENT<span class="token punctuation">}</span> <span class="token punctuation">;</span> <span class="token keyword">do</span>
	command_set
<span class="token keyword">done</span>
</code></pre>
<p><strong>Examples</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token comment" spellcheck="true"># 1- Listing all files in a directory.</span>
<span class="token keyword">for</span> i <span class="token keyword">in</span> * <span class="token punctuation">;</span><span class="token keyword">do</span>
	<span class="token keyword">if</span> <span class="token punctuation">[</span> -d <span class="token string">"<span class="token variable">$i</span>"</span> <span class="token punctuation">]</span> <span class="token punctuation">;</span><span class="token keyword">then</span>
		<span class="token keyword">echo</span> <span class="token string">"<span class="token variable">$i</span>"</span>
	<span class="token keyword">fi</span>
<span class="token keyword">done</span>

<span class="token comment" spellcheck="true"># 2</span>
<span class="token keyword">for</span> i <span class="token keyword">in</span> <span class="token punctuation">{</span>1<span class="token punctuation">..</span>5<span class="token punctuation">}</span> <span class="token punctuation">;</span> <span class="token keyword">do</span>
	<span class="token keyword">echo</span> <span class="token string">"Welcome <span class="token variable">$i</span> times"</span>
<span class="token keyword">done</span>

<span class="token comment" spellcheck="true"># 3</span>
<span class="token keyword">for</span> i <span class="token keyword">in</span> <span class="token punctuation">{</span>0<span class="token punctuation">..</span>10<span class="token punctuation">..</span>2<span class="token punctuation">}</span> <span class="token punctuation">;</span><span class="token keyword">do</span>
	<span class="token keyword">echo</span> <span class="token string">"Welcome <span class="token variable">$i</span> times"</span>
<span class="token keyword">done</span>

<span class="token comment" spellcheck="true"># 4</span>
<span class="token keyword">for</span> <span class="token variable"><span class="token punctuation">((</span> c<span class="token operator">=</span><span class="token number">1</span><span class="token punctuation">;</span> c<span class="token operator">&lt;=</span><span class="token number">5</span><span class="token punctuation">;</span> c<span class="token operator">++</span> <span class="token punctuation">))</span></span> <span class="token punctuation">;</span><span class="token keyword">do</span>
	<span class="token keyword">echo</span> <span class="token string">"Welcome <span class="token variable">$c</span> times"</span>
<span class="token keyword">done</span>

<span class="token comment" spellcheck="true"># 5</span>
<span class="token keyword">for</span> <span class="token variable"><span class="token punctuation">((</span> <span class="token punctuation">;</span> <span class="token punctuation">;</span> <span class="token punctuation">))</span></span> <span class="token punctuation">;</span><span class="token keyword">do</span>
<span class="token keyword">echo</span> <span class="token string">"infinite loops [ hit CTRL+C to stop]"</span>
<span class="token keyword">done</span>

<span class="token comment" spellcheck="true"># 6- Count executables in directory</span>
count<span class="token operator">=</span>0
<span class="token keyword">for</span> i <span class="token keyword">in</span> *<span class="token punctuation">;</span> <span class="token keyword">do</span>
	<span class="token keyword">if</span> <span class="token function">test</span> –x <span class="token variable">$i</span> <span class="token punctuation">;</span> <span class="token keyword">then</span>
	 count<span class="token operator">=</span><span class="token variable"><span class="token variable">`</span><span class="token function">expr</span> $count + 1<span class="token variable">`</span></span>
	<span class="token keyword">fi</span>
<span class="token keyword">done</span>
<span class="token keyword">echo</span> Total of <span class="token variable">$count</span> files executable

</code></pre>
<hr>
<h2 id="while-loop"><code>while</code> Loop</h2>
<blockquote>
<p>Execute consequent-commands as long as test-commands has an exit status of zero. <a href="http://ss64.com/bash/while.html">Read More</a></p>
</blockquote>
<p><strong>Syntax</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token keyword">while</span> test-command <span class="token punctuation">;</span><span class="token keyword">do</span>
	 commands
<span class="token keyword">done</span>
</code></pre>
<p><strong>Example</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token comment" spellcheck="true"># The value of i is tested in the while to see if it is less than or equal to 100.</span>

i<span class="token operator">=</span>1
sum<span class="token operator">=</span>0
<span class="token keyword">while</span> <span class="token punctuation">[</span> <span class="token variable">$i</span> -le 100 <span class="token punctuation">]</span> <span class="token punctuation">;</span><span class="token keyword">do</span>
 sum<span class="token operator">=</span><span class="token variable"><span class="token variable">`</span><span class="token function">expr</span> $sum + $i<span class="token variable">`</span></span>
 i<span class="token operator">=</span><span class="token variable"><span class="token variable">`</span><span class="token function">expr</span> $i + 1<span class="token variable">`</span></span>
<span class="token keyword">done</span>
<span class="token keyword">echo</span> The <span class="token function">sum</span> is <span class="token variable">$sum</span><span class="token keyword">.</span>
</code></pre>
<hr>
<h2 id="until-loop"><code>until</code> Loop</h2>
<blockquote>
<p>Execute consequent-commands as long as test-commands has an exit status which is not zero. <a href="http://ss64.com/bash/until.html">Read More</a></p>
</blockquote>
<p><strong>Syntax</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token keyword">until</span> test-command<span class="token punctuation">;</span> <span class="token keyword">do</span>
	commands
<span class="token keyword">done</span>
</code></pre>
<p><strong>Example</strong></p>
<pre class=" language-bash"><code class="prism  language-bash">number<span class="token operator">=</span>0
<span class="token keyword">until</span> <span class="token punctuation">[</span> <span class="token variable">$number</span> -ge 10 <span class="token punctuation">]</span><span class="token punctuation">;</span> <span class="token keyword">do</span>
	<span class="token keyword">echo</span> <span class="token string">"Number = <span class="token variable">$number</span>"</span>
	number<span class="token operator">=</span><span class="token variable"><span class="token variable">$((</span>number <span class="token operator">+</span> <span class="token number">1</span><span class="token variable">))</span></span>
<span class="token keyword">done</span>
</code></pre>
<h2 id="case"><code>case</code></h2>
<blockquote>
<p>Conditionally perform a command, case will selectively execute the command-list corresponding to the first pattern that matches word.  <a href="http://ss64.com/bash/case.html">Read More</a></p>
</blockquote>
<p><strong>Syntax</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token keyword">case</span> word <span class="token keyword">in</span>
 patterns <span class="token punctuation">)</span> 
	 commands
 <span class="token punctuation">;</span><span class="token punctuation">;</span>
 pattern <span class="token punctuation">)</span> 
	 <span class="token function">command</span>
esac
</code></pre>
<p><strong>Example</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token keyword">echo</span> -n <span class="token string">"Type a digit or a letter &gt; "</span>
<span class="token function">read</span> character

<span class="token keyword">case</span> <span class="token variable">$character</span> <span class="token keyword">in</span>
 <span class="token punctuation">[</span>a-z<span class="token punctuation">]</span> <span class="token operator">|</span> <span class="token punctuation">[</span>A-Z<span class="token punctuation">]</span> <span class="token punctuation">)</span> <span class="token keyword">echo</span> <span class="token string">"You typed the letter <span class="token variable">$character</span>"</span> <span class="token punctuation">;</span><span class="token punctuation">;</span>
 <span class="token punctuation">[</span>0-9<span class="token punctuation">]</span> <span class="token punctuation">)</span> <span class="token keyword">echo</span> <span class="token string">"You typed the digit <span class="token variable">$character</span>"</span> <span class="token punctuation">;</span><span class="token punctuation">;</span>
 * <span class="token punctuation">)</span> <span class="token keyword">echo</span> <span class="token string">"You did not type a letter or a digit"</span>
esac
</code></pre>
<h2 id="break-and-continue"><code>break</code> and <code>continue</code></h2>
<p><strong>Examples for <code>break</code></strong></p>
<pre class=" language-bash"><code class="prism  language-bash">
<span class="token comment" spellcheck="true"># 1</span>
a<span class="token operator">=</span>0
<span class="token keyword">while</span> <span class="token punctuation">[</span> <span class="token variable">$a</span> -lt 10 <span class="token punctuation">]</span> <span class="token punctuation">;</span><span class="token keyword">do</span>
	<span class="token keyword">echo</span> <span class="token variable">$a</span>
	<span class="token punctuation">[</span> <span class="token variable">$a</span> -eq 5 <span class="token punctuation">]</span> <span class="token operator">&amp;&amp;</span> <span class="token keyword">break</span>
<span class="token keyword">done</span>
a<span class="token operator">=</span><span class="token variable"><span class="token variable">`</span><span class="token function">expr</span> $a + 1<span class="token variable">`</span></span>

<span class="token comment" spellcheck="true"># 2</span>
<span class="token keyword">for</span> var1 <span class="token keyword">in</span> 1 2 3 <span class="token punctuation">;</span><span class="token keyword">do</span>
	<span class="token keyword">for</span> var2 <span class="token keyword">in</span> 0 5 <span class="token punctuation">;</span><span class="token keyword">do</span>
		 <span class="token keyword">if</span> <span class="token punctuation">[</span> <span class="token variable">$var1</span> -eq 2 -a <span class="token variable">$var2</span> -eq 0 <span class="token punctuation">]</span> <span class="token punctuation">;</span><span class="token keyword">then</span>
			 <span class="token keyword">break</span> 2
		 <span class="token keyword">else</span>
			 <span class="token keyword">echo</span> <span class="token string">"<span class="token variable">$var1</span> <span class="token variable">$var2</span>"</span>
		 <span class="token keyword">fi</span>
	<span class="token keyword">done</span>
<span class="token keyword">done</span>
</code></pre>
<p><strong>Examples for <code>continue</code></strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token comment" spellcheck="true"># 1</span>
NUMS<span class="token operator">=</span><span class="token string">"1 2 3 4 5 6 7"</span> 
<span class="token keyword">for</span> NUM <span class="token keyword">in</span> <span class="token variable">$NUMS</span> <span class="token punctuation">;</span><span class="token keyword">do</span>
	 Q<span class="token operator">=</span><span class="token variable"><span class="token variable">`</span><span class="token function">expr</span> $NUM % 2<span class="token variable">`</span></span>
	 <span class="token keyword">if</span> <span class="token punctuation">[</span> <span class="token variable">$Q</span> -eq 0 <span class="token punctuation">]</span> <span class="token punctuation">;</span><span class="token keyword">then</span>
		 <span class="token keyword">echo</span> <span class="token string">"Number is an even number!!"</span>
		 <span class="token keyword">continue</span>
	 <span class="token keyword">fi</span>
	<span class="token keyword">echo</span> <span class="token string">"Found odd number"</span>
<span class="token keyword">done</span>

</code></pre>
<h1 id="brackets">Brackets</h1>
<h2 id="group-commands-in-a-subcurrent--shell">Group commands in a sub/current  shell</h2>
<blockquote>
<p>Grouping a (list of commands) in parenthesis causes them to be executed as if they were a single unit. When commands are grouped, redirections can be applied to the entire command list. For example, the output of all the commands in the list can be redirected to a single stream. <a href="http://ss64.com/bash/syntax-brackets.html">ReadMore</a></p>
</blockquote>
<p>Placing a list of commands between curly braces causes the list to be executed in the current shell context. No subshell is created. The semicolon (or newline) following list is required.<br>
<strong>Syntax</strong></p>
<pre><code>(commands)
</code></pre>
<p>Placing a list of commands between parentheses causes a subshell to be created, and each of the commands in list to be executed in that subshell. Since the list is executed in a subshell, variable assignments do not remain in effect after the subshell completes.</p>
<p><strong>Syntax</strong></p>
<pre><code>   {commands}
</code></pre>
<p><strong>Example</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token punctuation">(</span>echo a<span class="token punctuation">;</span><span class="token keyword">echo</span> b<span class="token punctuation">)</span><span class="token operator">&gt;</span>file
</code></pre>
<h2 id="return-a-binary-result-of-expression">Return a binary result of expression</h2>
<blockquote>
<p>Return a status of 0 or 1 depending on the evaluation of the conditional expression. Word splitting and filename expansion are not performed on the words between the <code>[[</code> and <code>]]</code> tilde expansion, parameter and variable expansion, arithmetic expansion, command substitution, process substitution, and quote removal are performed.</p>
</blockquote>
<p><strong>Syntax</strong></p>
<pre><code>   [[ expression ]] 
</code></pre>
<p>When the <code>==</code> and <code>!=</code> operators are used, pattern matching will be done on the - string to the right of the operator.</p>
<p>The return value is 0 if the string matches or does not match the pattern, respectively, and 1 otherwise.</p>
<p>Any part of the pattern can be quoted to force it to be matched as a string.</p>
<p><strong>Example</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token punctuation">[</span><span class="token punctuation">[</span> <span class="token variable">$age</span><span class="token operator">&gt;</span>30 <span class="token operator">&amp;&amp;</span> <span class="token variable">$age</span><span class="token operator">&lt;</span>60 <span class="token punctuation">]</span><span class="token punctuation">]</span> <span class="token operator">&amp;&amp;</span> <span class="token keyword">echo</span> <span class="token string">"FOO"</span>
</code></pre>
<h2 id="arithmetic-expansion">Arithmetic expansion</h2>
<blockquote>
<p>Arithmetic expansion allows the evaluation of an arithmetic expression and the substitution of the result.<br>
The expression is treated as if it were within double quotes, but a double quote inside the parentheses is not treated specially. All tokens in the expression undergo parameter expansion, command substitution, and quote removal. Arithmetic substitutions can be nested.</p>
</blockquote>
<p><strong>Syntax</strong></p>
<pre><code>$(( expression ))
</code></pre>
<p><strong>Example</strong></p>
<pre class=" language-bash"><code class="prism  language-bash"><span class="token variable"><span class="token punctuation">((</span>a<span class="token operator">=</span><span class="token number">3</span><span class="token operator">*</span><span class="token number">3</span><span class="token punctuation">))</span></span>
</code></pre>
