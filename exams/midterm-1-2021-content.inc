\begin{enumerate}
\item Let $a,b,c,d\in\R$ satisfy $ad-bc=1$, and set
\[
  f(z)=\frac{az+b}{cz+d},\qquad
  \Hupper=\{z\in\C:\operatorname{Im}z>0\}.
\]
\begin{enumerate}
\item \textbf{(2 points)} Show that $f$ maps $\Hupper$ into $\Hupper$.
\worked{Since $cz+d\neq0$ for $z\in\mathbb{H}$ (its zero, if any, is real), we have $$ f( z ) = \frac{az + b }{cz + d} = \frac{ (az + b)(c \overline{z}+d)}{|cz+d|^2} = \frac{ ac |z|^2 + bc \overline{z} + ad z + bd}{|cz+d|^2}. $$ So if $z=x+iy$ and $\overline{z}= x- iy$, then $$\Im \, f(z) =  \frac{y(-bc+ ad) }{|cz+d|^2} = \frac{ y }{|cz+d|^2} > 0,$$ where we have used the fact that $ad- bc=1$ and also that $y > 0$.}
\item \textbf{(2 points)} Is $f:\Hupper\to\Hupper$ holomorphic?
\worked{As both $az+b$ and $cz+d$ are holomorphic (they are polynomials, hence entire), the ratio is also holomorphic whenever $cz +d \neq 0$. If $c\neq0$, the only zero of $cz+d$ is $z=-d/c$, which is real. If $c=0$, then $d\neq0$ since $ad-bc=1$. Thus $cz+d$ does not vanish anywhere on $\mathbb{H}$.}
\item \textbf{(5 points)} A line or circle can be given by an equation
\[
  Ax+By+C(x^2+y^2)=D,
\]
where $A,B,C,D\in\R$ and $z=x+iy$. For the choice $(a,b,c,d)=(0,-1,1,0)$, show that $f(z)=-1/z$ sends the portion of such a line or circle in $\Hupper$ to the portion of a line or circle in $\Hupper$.
\worked{Note that if $z = x+ iy$, then $$ f(z) = -1/z = \frac{-x}{x^2+y^2} + i \frac{y}{x^2+y^2}. $$ Let $u(x, y) = \frac{-x}{x^2+y^2}$ and $v(x, y) = \frac{y}{x^2+y^2}.$ Note that $$ u^2 + v^2 = \frac{1}{x^2+y^2 }.$$ If $x, y$ satisfy $A x + B y + C (x^2+y^2)= D$, then also $$ A \frac{x}{x^2+y^2} + B \frac{y}{x^2+y^2} + C = D \frac{1}{x^2+y^2}.$$ Rewriting this in terms of $u$ and $v$ we obtain: $$ - A u + B v + C =D ( u^2 + v^2). $$ Rearranging this, we find that $u, v$ satisfy $$ (-A ) u + B v + (-D) (u^2 + v^2) = -C, $$ which is the equation of a circle/line in the $u-v$ plane. Since $f(f(z))=z$ for $z\in\mathbb{H}$, this equation describes precisely the image in $\mathbb{H}$.}
\end{enumerate}

\item Consider the real function
\[
  f(x)=\begin{cases}e^{-1/x^2},&x\ne0,\\0,&x=0.\end{cases}
\]
\begin{enumerate}
\item \textbf{(3 points)} Show that $f$ is infinitely differentiable at $0$ and compute every $f^{(k)}(0)$. You may use that a rational function of $x$ multiplied by $e^{-1/x^2}$ tends to $0$ as $x\to0$.
\worked{By definition $$f'(0) = \lim_{h \rr 0} \frac{ e^{-1/h^2} - f(0) }{h} = \lim_{h \rr 0} \frac{ e^{-1/h^2} }{h} = 0 $$ where we have used the hint as well as the fact that $f(0)=0$. Now, we proceed inductively assuming that $f^{(k)}(0)=0$ and show that $f^{(k+1)} (0)=0$ as well. Indeed, by definition $$ f^{(k+1)} (0) = \lim_{h \rr 0 } \frac{f^{(k)}(h)-  f^{(k)}(0)}{h}.$$ Now for $x \neq 0$, the function $e^{-1/x^2}$ is certainly differentiable, since $e^x$ is differentiable, $-1/x^2$ is differentiable, and we can use the chain rule. In fact, one can easily verify by induction on $k$ that there exist polynomials $p_k(x), q_k(x)$ such that, for $h \neq 0$, $q_k(h)\neq0$ and we have \be{f:der} f^{(k)}(h) = \frac{p_k(h)}{q_k(h)} e^{ -1/h^2}. \ee The case $k=0$ has $p_0=q_0=1$. Indeed, suppose the claim is true for $j=k-1.$ Then by the product rule, $$ f^{(k)}(h) = \frac{d}{dh} \left( \frac{p_{k-1}(h)}{q_{k-1}(h)}  \right) e^{ -1/h^2} + \frac{2}{h^3} \frac{p_{k-1}(h)}{q_{k-1}(h)} e^{ -1 /h^2}, $$ again for $h \neq 0$. But the derivative of a rational function is again a rational function, so the inductive claim has been proven. Now use the hint and (\ref{f:der}) to conclude that $f^{(k+1)}(0)=0$ as well.}
\item \textbf{(3 points)} Prove or disprove: an analytic function on a complex neighborhood of $0$ agrees with $f$ on the real axis near $0$.
\worked{Suppose that $g(z)$ is an analytic function around $0$ agreeing with $f(x)$ for points on the real axis with $|x|$ sufficiently small. By what we showed in class, if $ \sum_{n \geq 0} a_nT^n$ is the formal series such that $g(z) = \sum_{n \geq 0} a_nz^n$ for $z$ near $0$, then $a_k = \frac{g^{(k)}(0)}{k!}. $ As $g$ agrees with $f$ on points along the real axis, we may as well compute the $\C$-derivatives of $g(z)$ by approaching $0$ through real values. Hence, we are reduced to the computation from the previous part, and so $a_k=0$ for all $k$. In other words, $g(z)$ must be $0$ near $0$, a contradiction since $f(x)$ is non-zero near $0.$}
\end{enumerate}

\newpage
\item \textbf{(10 points)} Suppose
\[
  f(T)=1+a_1T+a_2T^2+\cdots
\]
has positive radius of convergence and every $a_k$ is a positive real number. The formal inverse $g(T)=\sum_{n\ge0}b_nT^n\in\C[[T]]$ satisfies $f(T)g(T)=1$. Prove that $g$ also has positive radius of convergence.\par
\emph{Hint.} First find a recurrence for $b_n$, then choose $0<\delta<1$ such that $\sum_{k\ge1}a_k\delta^k<1$.
\worked{From the relation $g(T) f(T) =1$, if we collect the coefficients of $T^n$ we get the following relations \be{} T^0 &: &\, 1 \cdot b_0 =1 \\
T^1 &:& b_1 + a_1 b_0 = 0 \\
T^2 &:& b_2 + a_1 b_1 + a_2 b_0 = 0 \\
\vdots &:& \nonumber \\
T^n &:& b_n + a_1 b_{n-1} + \cdots + a_{n-1} b_1 + a_n b_0 = 0
 \ee
Solving for $b_n$ in the last relation, we obtain that \be{b:rel} b_n = - \sum_{k=1}^{n} a_{k} b_{n-k}. \ee Now write $$f(T)= \sum_{n \geq 0} a_n T^n= 1 + h(T), \text{ so that } h(T) = a_1 T + a_2 T^2 + \cdots. $$

If $f(T)=1$, then clearly $g(T)=1$ has a positive radius of convergence and there is nothing to prove, so assume $f(T)$ is non-constant and hence  $h(T) \neq 0$. Note that $f(T)$ and $h(T)$ have the same radius of convergence, denote this radius by $r$.

On $D(0, r)$, $h(z)$ is continuous, and $h(0)=0$. So by continuity we can choose $0 < \delta < \min\{1,r\}$ such that on $\overline{D(0, \delta)}$ we have $|h(z)| < 1$. We shall contend that $$ | b_n | \leq \frac{1}{\delta^n}, $$ which, by Hadamard, shows that $g(T)$ has radius of convergence at least $\delta$.

We can prove the claim by induction, where $b_0=1$ so the $n=0$ case is verified. Now assume the inductive claim for all $b_j$ with $j < n$. Then we compute using \eqref{b:rel} that $$ | b_n | \leq \sum_{k=1}^{n} |a_{k}| \frac{1}{\delta^{n-k}} = \frac{1}{\delta^n} \sum_{k=1}^{n} a_k \delta^k \leq \frac{1}{\delta^n} \sum_{k \geq 1} a_k \delta^k \leq  \frac{1}{\delta^n} ,$$ where in the last line we have used the fact that $a_j$ are real, positive and also that $ \sum_{k \geq 1} a_k \delta^k = h(\delta)$.}
\end{enumerate}
