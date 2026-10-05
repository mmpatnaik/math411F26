\begin{enumerate}
\item \begin{enumerate}
\item \textbf{(3 points)} Find every solution of $z^3=-8i$. You may leave your answers in polar form $re^{i\theta}$.
\worked{Write $z=re^{i\theta}$. Since $-8i=8e^{3\pi i/2}$, we have $r^3=8$ and $3\theta=3\pi/2+2\pi k$. Thus $r=2$ and the three distinct roots are
\[
  z_k=2\exp\!\left(i\left(\frac{\pi}{2}+\frac{2\pi k}{3}\right)\right),
  \qquad k=0,1,2.
\]}
\item \textbf{(4 points)} Let $r>0$ be real and $w\in\C$. Show that
\[
  \left|\frac{w-r}{1-r\overline w}\right|\le1
  \quad\text{when }r<1\text{ and }|w|<1.
\]
\worked{The denominator is nonzero because $|r\overline w|<1$. Compare the squares of the two moduli:
\begin{align*}
  |w-r|^2&=|w|^2-r(w+\overline w)+r^2,\\
  |1-r\overline w|^2&=1-r(w+\overline w)+r^2|w|^2.
\end{align*}
Thus $|w-r|^2\leq|1-r\overline w|^2$ is equivalent to
\[
  (1-r^2)(1-|w|^2)\geq0.
\]
Both factors are positive under the stated hypotheses. In fact the inequality is strict, so the quotient has modulus less than $1$.}
\end{enumerate}

\item \textbf{(9 points)} Let $D=\{z\in\C:|z|<1\}$ and let $f=u+iv$ be holomorphic on $D$. Suppose $|f|^2=u^2+v^2=c$ throughout $D$, where $c>0$. Prove that $f$ is constant.\par
\emph{Hint.} Differentiate $u^2+v^2=c$ with respect to $x$ and $y$. You may use that a real function with continuous partial derivatives and both partial derivatives zero on $D$ is constant.
\worked{Differentiating gives $u u_x+v v_x=0$ and $u u_y+v v_y=0$. The Cauchy--Riemann equations say $v_x=-u_y$ and $v_y=u_x$, so
\[
  \begin{pmatrix}u&-v\\v&u\end{pmatrix}
  \begin{pmatrix}u_x\\u_y\end{pmatrix}=\begin{pmatrix}0\\0\end{pmatrix}.
\]
The matrix has determinant $u^2+v^2=c>0$. Hence $u_x=u_y=0$; the Cauchy--Riemann equations also give $v_x=v_y=0$. Both $u$ and $v$ are constant on the connected disc $D$, so $f$ is constant.}

\item \textbf{(9 points)} Let $f$ be entire and analytic, and set
\[
  A_n=\{z\in\C:f^{(n)}(z)=0\},\qquad n\ge0.
\]
\begin{enumerate}
\item Show that $A_n$ is closed. Show also that $A_n$ is discrete if $f^{(n)}$ is not identically zero. What is $A_n$ if $f^{(n)}$ is identically zero?\par
Here \emph{discrete} means that every point of the set has a neighborhood containing no other point of the set.
\worked{The derivative $f^{(n)}$ is continuous, so its zero set $A_n$ is closed. If $f^{(n)}$ is not identically zero, the isolated zeros theorem makes each point of $A_n$ isolated; thus $A_n$ is discrete. If $f^{(n)}\equiv0$, then $A_n=\C$, which is closed but not discrete.}
\item Suppose that for every $a\in\C$, at least one coefficient in the Taylor expansion
\[
  f(z)=\sum_{n\ge0}c_n(a)(z-a)^n
\]
is zero. Show that $f$ is a polynomial. You may use part (a) and the fact that $\C$ is uncountable.
\worked{Assume instead that $f$ is not a polynomial. Then no $f^{(n)}$ vanishes identically, since $f^{(n)}\equiv0$ would make $f$ a polynomial. By part (a), each $A_n$ is discrete and closed. Each discrete subset of $\C$ is countable: for each point choose a disc with rational center and rational radius that contains it but no other point of the subset. Distinct points require distinct such discs, and there are only countably many rational discs.

Now $c_n(a)=f^{(n)}(a)/n!$. The hypothesis therefore says that every $a$ belongs to at least one $A_n$, so $\C=\bigcup_{n\ge0}A_n$. The right side is countable, contrary to the uncountability of $\C$. Thus $f$ is a polynomial.}
\end{enumerate}
\end{enumerate}
