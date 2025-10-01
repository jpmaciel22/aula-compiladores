regex apenas emails .com.br
```
^([\w.%-+]+@[\w][\w.-]*\.com\.br)$
```

email mais restritivo:
```
^([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})$
```

cpf com ou sem ponto
```
^(\d{3}\.\d{3}\.\d{3}-\d{2}|\d{11})$
```

cep 
```
^(\d{2}\.\d{3}-\d{3})$ ou ^(\d{5}-\d{3})$
```

data
```
^(\d{2}\/\d{2}\/\d{4})$
```

== REGEX SYNTAX ==
```
. | qualquer char
* | zero ou mais ocorrencias do elemento anterior
+ | 1 ou mais ocorrencias do elemento antereior
? | 0 ou 1 ocorrencia do elemento anterior
^ | marca o inicio de uma linha ou negacao dentro de colchetes
$ | indica o final de uma linha
| | significa OU este expressoes sendo um operador 
[] | define um conjunto de caracteres possiveis em uma posicao
{n} | exatamente n ocorrencias
{n,} | no minimo n ocorrencias
{n,m} | entre n e m ocorrencias
() | agrupa expressoes
(?:padrao) | grupo nao capturante
\d | digitos
\w | caracteres alfanumericos
\s | espacos em branco
para capturar literais ao inves de simbolos regex usa-se \ antes, exemplo: \. para capturar pontos
ao inves de utilizar a expressao .
```

== definicoes ==

Lexema: unidade mínima de significado em uma língua. Sequência de caracteres do programa fonte. ex: int, soma, + , (

Padrão: descricao da forma em que os lexemas podem assumir. regras do que é aceito na linguagem. Ex: if ( palavra reservada if)

Tokens: Lexema que segue um padrão válido. resultado da classificação. Par: token e atributo. São unidades básicas de análise de um programa de computador. 
ex: <pr, "if"> ( token da palavra reservada if)
ex: <id, 1> ---> tabela de simbolos: 1 | soma | int

tabela de simbolos: estrutura de dados que contém registros para cada identificador e atributos. não é uma etapa da análise léxica porem todas as análises relacionam-se com a tabela de simbolos.

Funcoes do analisador lexico: Identificar lexemas, classificá-los de acordo com os padroes de tokens e remover espaços em branco. ( também manipula a tabela de simbolos e gera a lista de tokens )

Abordagens:
-  Análise léxica completa: Toda a análise é feita de uma só vez, entregando ao analisador sintático a lista de tokens de forma completa e de uma só vez. Desvantagem: Eficiencia, se houve erro sintático, por exemplo, encontrará todos os erros antes de parar.
- Por token e orquestrado pelo analisador sintatico. Gera um token de cada vez e de forma integrada com o sitnatico. Aqui para logo no primeiro erro.

Importancia da análise léxica: Processamento de linguagens naturais, identificando e classificando os elementos básicos da linguagem. Base para compiladores e interpretadores já que é seu primeiro passo ao identificar , classificar e dividir o código-fonte em tokens significativos para as etapas de análise seguintes. Importante para segurança de sistemas analisando erros de sintaxe.

Lexemas são identificados por meio de AFDs e Regex.

Linguagem: Conjunto contável de possíveis cadeias de um determinado alfabeto.

Alfabeto: Conjunto finito de símbolos. 

Cadeia: Sequência finita de caracteres à partir de um alfabeto

Expressões Regulares: Notação que define padrões de regras para identificação de símbolos que estão de acordo com esta estrutura. Especifica como os símbolos do alfaabeto podem formar cadeias segundo esta linguagem (lexemas). 

```
<pr, public> <pr, static> <type, "void"> <id, 1> <LP> <id, 9><[> <]> <id, 2> <RP> <LB>
<type, "int"> <id,3> <ATTR> <num, 10> <,> <id, 4> <ATTR> <num, 4> <;>
<type, "float"> <id, 5> <ATTR> <id,3> </> <id,4> <;>
<id, 6><.><id, 7><.><id, 8> <LP> <id, 5> <RP> <;>
<RB>

public static void main(String [] args) {
	int a = 10, b = 4;
	float c = a / b;
	System.out.print(c);
}

==================
| main | func | 1 |
| args | param | 2 |
| a | int | 3 |
| b | int | 4 |
| c | float | 5 |
| System | class | 6 |
| out | attribute | 7 |
| print | func | 8 |
| String | class | 9 |
==================

```