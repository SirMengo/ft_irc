/* 
! Itens que cada client precisa ter

	-> FD - Ligação dele.
	-> Nickname - Adquirido com o comando NICK e não pode ser repetido.
	-> Username - Adquirido com a função USER.
	-> Estado da Autentificação - Se já colocou a pass coreta.
	-> Estado de Registro - Se esta com tudo em cima válido.
	-> Canais em que está - Saber em que canais exato cada client está 
	para não ter mensagens duplas.

! Funções uteis
	-> Check de duplicata de nicknames.
	-> Checar se é um comando valido e separar o comandos dos args.
	-> Checar se o Nickname é valido.
	-> Checar se tem \r\n no buffer.
	-> Juntar e limpar o buffer.


! Funções para fazer:
	Check de password; - Uteis
	Check se o client ja foi registrado; - Uteis
	Check se todas as informações acima são validas. - Uteis
	Checar se o nickname é valido. - Uteis
	Check de duplicatas de nickname. -  Uteis

______________________________________________________________________________________
	* Guia da tua parte (Client), por ordem
1. Alinhar com o teu colega

    Decidir quem guarda a relação cliente-canal (recomendo o Channel).
    Decidir quem valida o nick e quem verifica a unicidade (o Server).
    Definir como o Client entrega linhas completas ao tratamento de comandos.
    Definir como o colega manda uma resposta a um cliente (uma função do Client que acrescenta ao buffer de saída).
    Combinar quem fecha o fd e quem trata da limpeza.

2. Definir o estado do Client

    Listar os atributos (fd, identidade, host, estados, buffers) e escolher os nomes.
    Decidir os valores iniciais: cliente novo = não autenticado, não registado, sem nick nem user.
    Decidir como lidar com cópias (normalmente proibi-las, por causa do fd).

3. Criar o Client no accept

    Receber o fd e o endereço do cliente.
    Guardar o IP em texto.
    Garantir que o fd está em modo não bloqueante.
    Registar o Client na estrutura do Server (isto é feito em conjunto com o Server).

4. Receção de dados

    Ler do socket e acrescentar ao buffer de entrada.
    Distinguir os três resultados da leitura: chegaram dados, o cliente fechou, erro/nada para ler.
    Extrair linhas completas (por \n, tratando o \r opcional) e deixar o resto no buffer.
    Ignorar linhas vazias.
    Definir o limite de 512 caracteres por mensagem e o limite do buffer total, e o que fazer se forem excedidos.
    Testar o caso de comandos partidos e de vários comandos numa só leitura.

5. Envio de dados

    Criar a função que acrescenta uma mensagem ao buffer de saída (já com \r\n).
    Enviar quando o socket estiver pronto a escrever, sem bloquear.
    Tratar o envio parcial: remover do buffer só o que foi realmente enviado.
    Indicar ao servidor quando há dados pendentes (para ativar ou desativar o evento de escrita no poll()).
    Decidir o que fazer com clientes lentos cujo buffer cresce demais.

6. Identidade e estados

    Getters e setters para nick, user, realname e host.
    Marcar autenticado quando o colega validar o PASS.
    Calcular o registo: autenticado, com nick e com user.
    Garantir que a boas-vindas só é enviada uma vez, no momento em que passa a registado.
    Fornecer o prefixo nick!user@host, com um valor sensato antes de o cliente ter nick (por exemplo *).

7. Desconexão

    Detetar a queda de ligação ou o QUIT.
    Sinalizar ao Server que o cliente deve ser removido.
    Fechar o fd e libertar tudo o que é do Client, sem fugas de memória ou de descritores.
    Combinar com o colega a remoção dos canais e o aviso aos outros membros.

8. Testes

    Ligar com nc e enviar comandos completos.
    Enviar um comando em várias partes (Ctrl+D) e vários comandos de uma vez.
    Enviar uma linha enorme sem quebra de linha.
    Ligar e desligar muitos clientes e verificar fugas de memória e de fds.
    Desligar um cliente abruptamente a meio de um envio.
    Testar com um cliente IRC real (irssi, HexChat), que envia PASS, NICK e USER em sequência e muito depressa.

9. Revisão final

    Confirmar que nada bloqueia (leitura, escrita, nem em casos de erro).
    Confirmar que um cliente problemático nunca derruba o servidor.
    Rever nomes e responsabilidades da classe para ficar simples e sem dependências desnecessárias.

Podemos aprofundar qualquer um destes passos, por exemplo o 4 (receção de dados), que é onde costumam aparecer mais bugs.
*/