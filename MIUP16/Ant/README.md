### Objectivo:

Calcular o valor total que o grasshopper vai pagar a formiga (com amortização)

### Input:

A primeira linha de input o numero de casos `N`.

Em cada linha recebemos tres valores, `y, B, r` que representam `y` o numero de anos, `B` o total emprestado, `r` o rate dos interesses.

### Output:

Um output por caso com o total que a formiga tera de pagar arredondado as 3 casas decimais.

### Review

Seguindo a logica da resolução parcial, e sendo `p` o pagamento anual pela formiga:

```math
p=(B(1+r)^n)/ \Sigma{(n+r)^{n-1}}
```

Para implementar esta formula e tendo que fazer o sumatório acabariamos com o Pior caso de `O(n^2)`

Seja r o valor da p. geometrica

A sum de n membros seria

```math
Sn = a + ar + ar^2 + ... + ar^{n-1}
```

O proximo membro

```math
rSn = ar + ar^2 + ar^3 + ... + ar^{n}
```

sendo assim

```math
rSn - Sn = ar^n - a
```

```math
Sn(r-1) = a(r^n-1)
```

```math
Sn = {a(r^{n} - 1)}/{r-1}
```

Sendo obtendo um `O(n)`
