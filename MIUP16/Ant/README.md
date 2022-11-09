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
p=(B(1+r)^n)/ \Sigma{n+r^(n-1)}
```
