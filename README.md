<h2 align="center"> INSTITUTO SUPERIOR TÉCNICO </h2>
<h1 align="center"> Análise e Síntese de Algoritmos <br> <i> 2022/2023 </i> </h1>
<h2 align="center"> 2º Projecto </h2>
<h3 align="center"> <i>Data enunciado: 19 de Dezembro de 2022 <br>
Data Limite de Entrega: 06 de Janeiro de 2023 (18h00)</i> </h3>
<br>
<h2 align="left"> <b> Descrição do Problema </b> </h2>
<p align="left"> 
  O reforço das trocas comerciais por ferrovia de alta velocidade entre regiões vizinhas da Caracolândia, foi declarada uma prioridade, dada a ineficiente situação actual por rede rodoviária.
  Assim, o governo da Caracolândia, decidiu encomendar um estudo preliminar ao Instituto Superior Técnico para estimar qual o valor máximo de trocas comerciais passível de ser passado
  para a rede ferroviária.
  No entanto, algumas regiões não mantêm trocas comerciais com regiões vizinhas. Adicionalmente, devido a restrições orçamentais, o governo necessita de minimizar os custos de
  infraestrutura apenas financiando os troços estritamente necessários para conseguir garantir ligações entre o maior número de regiões e apenas entre as que já mantenham trocas comerciais.
  De forma a simplificar o problema, podemos assumir que:
</p>

- a localização de cada região pode ser caracterizada pela latitude/longitude da estação ferroviária da sua capital;

- as ligações entre as estações ferroviárias pode ser feita em linha recta (ignorando relevo ou outros obstáculos potenciais).
<br>
<div align="center">
  <img src="https://cdn.discordapp.com/attachments/1052333643231674451/1057454694374588496/image.png"  alt="Figura 1">
</div>
<br>
<p align="left">
  Em 1934, Boris Delaunay, definiu para um conjunto de pontos
  P dispostos num plano, uma triangulação T(P), tal que nenhum
  ponto p ∈ P está dentro de qualquer triângulo t ∈ T(P). Usando
  esta triangulação de Delaunay, dado um conjunto de pontos representando as estações ferroviárias da capital de cada região, é
  possível construir um grafo planar não dirigido G = (V,E), tal que
  V representa o conjunto de regiões e E representa as ligações entre estações ferroviárias da capital de cada região definidas como
  próximas pela triangulação.
  Neste projecto, assumimos que: os custos de cada troço de ferrovia são os mesmos; e que
  após a aplicação da triangulação de Delaunay obtemos um grafo G = (V,E), onde V designa
  uma região, e E o conjunto de arcos, onde a função de pesos w representa, para cada arco
  (u, v) ∈ E, o valor em MC de trocas comercias entre as regiões u e v. 
  <b>Problema</b>: dado um grafo G = (V,E) pretende-se calcular o valor máximo de trocas comerciais,
  minimizando os custos infraestrutura (i.e. número de troços).
</p>
<br>
<div align="center">
  <img src="https://cdn.discordapp.com/attachments/1052333643231674451/1057455543754698843/image.png" alt="Figura 2">
</div>
<br>
<h2 align="left"> <b> Input </b> </h2>
<p align="left">
  O ficheiro de entrada contendo a informação relativa ao problema a resolver, é definido da
  seguinte forma:
</p>

- uma linha contendo o número vértices |<i>V</i>| (com |<i>V</i>| ≥ 1);

- uma linha contendo o número arcos |<i>E</i>| (com |<i>E</i>| ≥ 0);

- uma sequência de |<i>E</i>| linhas, em que cada linha representa um arco (<i>u, v</i>) e contém 3
inteiros: dois inteiros que designam os vértices <i>u</i> e <i>v</i> e um inteiro que representa o valor
<i>w</i>(<i>u, v</i>).
<p align="left"> Os identificadores dos vértices são números inteiros entre 1 e |<i>V</i>|. </p>

<h2 align="left"> <b> Output </b> </h2>
<p align="left">
  O programa deverá escrever no output o valor máximo de trocas comerciais, minimizando os
  custos infraestrutura (i.e. número de troços).
</p>

<h2 align="left"> <b> Exemplos </b> </h2>
<h3 align="left"> <b> Input </b> </h3>
<p align="left"> 
8 <br>
11 <br>
1 2 2 <br>
1 5 4 <br>
1 8 3 <br>
2 6 8 <br>
2 5 4 <br>
2 8 9 <br>
4 3 1 <br>
3 7 3 <br>
4 7 4 <br>
5 6 8 <br>
6 8 5 <br>
</p>
<h3 align="left"> <b> Output </b> </h3>
<p> 36 </p>
