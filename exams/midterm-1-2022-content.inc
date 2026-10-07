\begin{enumerate}
\item \begin{enumerate}
\item \textbf{(3 points)} Find every solution of $z^3=-8i$. You may leave your answers in polar form $re^{i\theta}$.
\worked{Write $z=re^{i\theta}$, so $z^3=-8i=r^3e^{3i\theta}$. We have
\[
  -8i=8(-i)=8e^{i(3\pi/2)},
  \qquad r^3e^{i(3\theta)}=8e^{i(3\pi/2)}.
\]
Thus $r=2$ and, modulo $2\pi$, the three values of $\theta$ are
\begin{align*}
  \theta&=\frac{\pi}{2},\\
  \theta&=\frac{\pi}{2}+\frac{2\pi}{3}=\frac{7\pi}{6},\\
  \theta&=\frac{\pi}{2}+\frac{2\pi\cdot2}{3}=\frac{11\pi}{6}.
\end{align*}}
\item \textbf{(4 points)} Let $r>0$ be real and $w\in\C$. Show that
\[
  \left|\frac{w-r}{1-r\overline w}\right|\le1
  \quad\text{when }r<1\text{ and }|w|<1.
\]
\worked{The denominator is nonzero because $|\overline w r|<1$. Since $r\in\R$, we have $\overline r=r$, and
\begin{align*}
  \left|\frac{w-r}{1-\overline w r}\right|\le1
  &\Longleftrightarrow |w-r|\le|1-\overline w r|\\
  &\Longleftrightarrow |w-r|^2\le|1-\overline w r|^2\\
  &\Longleftrightarrow (w-r)(\overline w-r)\le(1-\overline w r)(1-wr)\\
  &\Longleftrightarrow w\overline w-r\overline w-rw+r^2
       \le1-\overline w r-wr+w\overline w r^2\\
  &\Longleftrightarrow |w|^2+r^2\le1+|w|^2r^2.
\end{align*}
This is true as $|w|^2<1$ and $r^2<1$: indeed,
\[
  1+|w|^2r^2-(|w|^2+r^2)=(1-r^2)(1-|w|^2)>0.
\]
In fact one has the strict inequality.}
\end{enumerate}

\ifsolutions\newpage\fi
\item \textbf{(9 points)} Let $D=\{z\in\C:|z|<1\}$ and let $f=u+iv$ be holomorphic on $D$. Suppose $|f|^2=u^2+v^2=c$ throughout $D$, where $c>0$. Prove that $f$ is constant.\par
\emph{Hint.} Differentiate $u^2+v^2=c$ with respect to $x$ and $y$. You may use that a real function with continuous partial derivatives and both partial derivatives zero on $D$ is constant.
\worked{Suppose $|f|^2=c$ with $c>0$. Differentiating the expression $|f|^2=c$ yields the two expressions
\begin{align*}
  2u u_x+2v v_x&=0,\\
  2u u_y+2v v_y&=0.
\end{align*}
Applying Cauchy--Riemann (i.e.\ $u_x=v_y$, $u_y=-v_x$) we find
\begin{align*}
  2u u_x-2v u_y&=0,\\
  2u u_y+2v u_x&=0.
\end{align*}
Since
\[
  \det\begin{pmatrix}u&-v\\v&u\end{pmatrix}=u^2+v^2\neq0,
\]
the only solution to this system is when $u_x=u_y=0$. In a similar way we also conclude that $v_x=v_y=0$. As the Jacobian matrix of the map $F=(u(x,y),v(x,y))$ vanishes, the map $F$ is locally constant, and hence constant since $D$ is connected.}

\ifsolutions\newpage\fi
\item \textbf{(9 points)} Let $f$ be entire and analytic, and set
\[
  A_n=\{z\in\C:f^{(n)}(z)=0\},\qquad n\ge0.
\]
\begin{enumerate}
\item Show that $A_n$ is closed. Show also that $A_n$ is discrete if $f^{(n)}$ is not identically zero. What is $A_n$ if $f^{(n)}$ is identically zero?\par
Here \emph{discrete} means that every point of the set has a neighborhood containing no other point of the set.
\worked{$A_n$ is closed and discrete if $f$ is analytic and $f^{(n)}\not\equiv0$. Otherwise $A_n=\C$, which is closed, but not discrete.

\emph{$A_n$ closed:} $f^{(n)}$ is continuous. Let $z\notin A_n$, say $f^{(n)}(z)=\varepsilon\neq0$. Pick a small neighborhood around $z$ such that
\[
  |f^{(n)}(z)-f^{(n)}(z')|<\frac{|\varepsilon|}{2}
  \quad\text{for }|z-z'|<\delta.
\]
Then all $z'\in B(z,\delta)$ satisfy $|f^{(n)}(z')|>0$. Thus the complement of $A_n$ is open, so $A_n$ is closed.

\emph{$A_n$ discrete:} As $f$ is analytic, so is $f^{(n)}$, and therefore if $f^{(n)}\not\equiv0$, it is given by a non-zero power series. If $z_0\in\C$ is such that $f^{(n)}(z_0)=0$ (i.e.\ $z_0\in A_n$), then by the isolated zeros theorem from class there is a small neighborhood around $z_0$ such that $f^{(n)}(z)\neq0$ on this neighborhood except at $z_0$. So this neighborhood meets $A_n$ only at $z_0$.}
\item Suppose that for every $a\in\C$, at least one coefficient in the Taylor expansion
\[
  f(z)=\sum_{n\ge0}c_n(a)(z-a)^n
\]
is zero. Show that $f$ is a polynomial. You may use part (a), the fact that closed discrete subsets of $\C$ are countable, and the fact that $\C$ is uncountable.
\worked{If $f$ is not a polynomial, $f^{(n)}(z)$ is non-zero (as a function) for all $n\ge0$, so each $A_n$ is countable by part (a). Indeed, each closed disc meets a closed discrete set in only finitely many points, since otherwise there would be an accumulation point in the set. Taking the union over discs of positive integer radius centered at $0$ proves countability. Therefore
\[
  \bigcup_{n\ge0}A_n\quad\text{is countable.}
\]
Note:
\[
  \bigcup_{n\ge0}A_n
  =\{a\in\C:f^{(n)}(a)=0\text{ for some }n\ge0\}.
\]
Now if
\[
  f(z)=\sum_{n\ge0}c_n(z-a)^n,
  \qquad\text{then}\qquad c_n=\frac{f^{(n)}(a)}{n!}.
\]
So our assumption implies
\[
  \C\subseteq\bigcup_{n\ge0}A_n,
\]
which contradicts countability unless $f^{(n)}\equiv0$ for some $n$, i.e.\ $f$ is a polynomial.}

\end{enumerate}
\end{enumerate}
