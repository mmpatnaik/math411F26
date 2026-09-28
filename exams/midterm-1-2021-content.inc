\begin{enumerate}
\item Let $a,b,c,d\in\R$ satisfy $ad-bc=1$, and set
\[
  F(z)=\frac{az+b}{cz+d},\qquad
  \Hupper=\{z\in\C:\operatorname{Im}z>0\}.
\]
\begin{enumerate}
\item \textbf{(2 points)} Show that $F$ maps $\Hupper$ into $\Hupper$.
\worked{The denominator cannot vanish on $\Hupper$: if $c\ne0$ its zero is the real number $-d/c$, while if $c=0$ then $d\ne0$. For $z=x+iy$,
\[
  \operatorname{Im}F(z)
  =\frac{(ad-bc)y}{|cz+d|^2}
  =\frac{y}{|cz+d|^2}>0.
\]}
\item \textbf{(2 points)} Is $F:\Hupper\to\Hupper$ holomorphic?
\worked{Yes. It is a quotient of holomorphic functions, and its denominator has no zero in $\Hupper$.}
\item \textbf{(5 points)} A line or circle can be given by an equation
\[
  Ax+By+C(x^2+y^2)=D,
\]
where $A,B,C,D\in\R$ and $z=x+iy$. For the choice $(a,b,c,d)=(0,-1,1,0)$, show that $F(z)=-1/z$ sends the portion of such a line or circle in $\Hupper$ to the portion of a line or circle in $\Hupper$.
\worked{Write $w=u+iv=-1/z$. As $z=-1/w$ and $w\in\Hupper$ by part (a),
\[
  x=-\frac{u}{u^2+v^2},\quad
  y=\frac{v}{u^2+v^2},\quad
  x^2+y^2=\frac{1}{u^2+v^2}.
\]
Substitution and multiplication by $u^2+v^2$ give
\[
  -Au+Bv-D(u^2+v^2)=-C.
\]
This is again an equation of the stated form: a line when $D=0$, or a circle when $D\ne0$ (provided the locus is nonempty). Since $F$ is its own inverse, this equation describes precisely the image in $\Hupper$.}
\end{enumerate}

\item Consider the real function
\[
  f(x)=\begin{cases}e^{-1/x^2},&x\ne0,\\0,&x=0.\end{cases}
\]
\begin{enumerate}
\item \textbf{(3 points)} Show that $f$ is infinitely differentiable at $0$ and compute every $f^{(k)}(0)$. You may use that a rational function of $x$ multiplied by $e^{-1/x^2}$ tends to $0$ as $x\to0$.
\worked{For $x\ne0$ put $t=1/x$. Induction gives $f^{(k)}(x)=P_k(t)e^{-t^2}$, with $P_0=1$ and
\[
  P_{k+1}(t)=-t^2P_k'(t)+2t^3P_k(t).
\]
Each $P_k$ is a polynomial. Suppose $f^{(k)}(0)=0$. Then
\[
  f^{(k+1)}(0)
  =\lim_{h\to0}\frac{f^{(k)}(h)-f^{(k)}(0)}{h}
  =\lim_{h\to0}\frac{P_k(1/h)e^{-1/h^2}}{h}=0.
\]
Starting with $f(0)=0$ proves that all derivatives exist and $f^{(k)}(0)=0$ for every $k\ge0$.}
\item \textbf{(3 points)} Prove or disprove: an analytic function on a complex neighborhood of $0$ agrees with $f$ on the real axis near $0$.
\worked{No such analytic function exists. Its complex derivatives at $0$ would equal the corresponding derivatives of its restriction to the real axis, hence would all be zero by part (a). Its Taylor series would therefore make it identically zero near $0$, but $f(x)>0$ for every real $x\ne0$.}
\end{enumerate}

\item \textbf{(10 points)} Suppose
\[
  F(T)=1+a_1T+a_2T^2+\cdots
\]
has positive radius of convergence and every $a_k$ is a positive real number. The formal inverse $G(T)=\sum_{n\ge0}b_nT^n\in\C[[T]]$ satisfies $F(T)G(T)=1$. Prove that $G$ also has positive radius of convergence.\par
\emph{Hint.} First find a recurrence for $b_n$, then choose $0<\delta<1$ such that $\sum_{k\ge1}a_k\delta^k<1$.
\worked{Comparison of coefficients gives $b_0=1$ and, for $n\ge1$,
\[
  b_n=-\sum_{k=1}^{n}a_k b_{n-k}.
\]
Since $\sum_{k\ge1}a_kT^k$ converges near $0$ and vanishes there, choose $\delta>0$ within its radius so that $S:=\sum_{k\ge1}a_k\delta^k<1$. We claim $|b_n|\le\delta^{-n}$. It holds for $n=0$. If it holds below $n$, then
\[
  |b_n|\le\sum_{k=1}^{n}a_k\delta^{-(n-k)}
  =\delta^{-n}\sum_{k=1}^{n}a_k\delta^k
  \le S\delta^{-n}<\delta^{-n}.
\]
Thus $\sum b_nT^n$ converges absolutely for $|T|<\delta$, so its radius of convergence is at least $\delta>0$.}
\end{enumerate}
