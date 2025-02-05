#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//ESTRUTURAS, VETORES E V�RI�VEIS GLOBAIS;
//-Structs
typedef struct {
    char nome[50], equipe[50], posicao[20], equipeDoJogador[50];
    int idade, camisa, golosMarcados;
    float altura, peso;

 } jogador;

 typedef struct {
    char nome[50], cidade[20], treinador[50];
    int anoFundacao, contadorJogadores, pontos;
    jogador jogadores[30];
     
 } equipe;

 typedef struct {
    char data[11], local[20];
    equipe equipe1, equipe2, vencedor;
    int golosEquipe1 , golosEquipe2;
 } partida;
 
typedef struct {
    char nome[50];
    equipe equipesParticipantes[20], campeao, viceCampeao, terceiroLugar;
    int numEquipes, numPartidas, ano;
    partida partidas[100];

} campeonato;

//-Vetores e Vari�veis
equipe equipes[100];
int totalEquipes = 0;

campeonato campeonatos[10];
int totalCampeonatos = 0; 

//DADOS DE LOGIN
const char usuarioCorreto[] = "admin";
const char senhaCorreta[] = "232163";

//FUN��ES
void removerQuebraDeLinha(char *texto){
    size_t tamanho = strlen(texto);
    if (tamanho > 0 && texto[tamanho-1] == '\n')
    {
        texto[tamanho-1] = '\0';
    }
    
}

int login() {
    char usuario[20], senha[20];
    int tentativas = 3;
    int escolha;

    while (tentativas > 0) {
        printf("\n--- INSIRA OS DADOS DE ADMINISTRADOR PARA INICIAR SESS�O---\n");
        printf("Usu�rio: ");
        scanf("%s", usuario);
        printf("Senha: ");
        scanf("%s", senha);

        if (strcmp(usuario, usuarioCorreto) == 0 && strcmp(senha, senhaCorreta) == 0) {
            system("cls");
            printf("\nLogin bem-sucedido!\n");
            return 1;
        } else {
            tentativas--;
            printf("\nDados incorretos! Tentativas restantes: %d\n", tentativas);

            if (tentativas > 0) {
                printf("Deseja tentar novamente? (Insira 1 para tentar novamente ou 0 para sair): ");
                scanf("%d", &escolha);

                if (escolha == 0) {
                    return 0;
                }
            }
        }
    }

   return 0;
}

//FUN��ES - EQUIPES
   
void cadastroEquipe(){
    int verificador = totalEquipes;
    equipe time;
    time.contadorJogadores = 0;
    time.pontos = 0;
    printf("Vamos fazer o cadastro da sua Equipe!\n\n");
    printf("Insira o nome da Equipe: ");
    getchar();    
    fgets(time.nome, sizeof(time.nome), stdin);
    removerQuebraDeLinha(time.nome);
    printf("\nInsira a cidade: " );
    fgets(time.cidade, sizeof(time.cidade), stdin);
    removerQuebraDeLinha(time.cidade);
    printf("\nInsira o ano de funda��o: " );
    scanf("%d", &time.anoFundacao);
    getchar();
    printf("\nInsira o nome do treinador: ");
    fgets(time.treinador, sizeof(time.treinador), stdin);
    removerQuebraDeLinha(time.treinador);
    equipes[totalEquipes] = time;
    totalEquipes++;

    if (verificador < totalEquipes){
    printf("\nNOME DA EQUIPE: %s | CIDADE: %s | ANO DE FUNDA��O: %d | TREINADOR: %s\nCADASTRO REALIZADO COM SUCESSO!", time.nome, time.cidade, time.anoFundacao, time.treinador);
    } else{
        printf("ERRO AO SALVAR.");
    };
}

void listarEquipes(){
    printf("\n\n\t\t\tEQUIPES CADASTRADAS\n\n\n");

    int i;
    for ( i = 0; i < totalEquipes; i++)
    {
        printf("ID: %d | NOME: %s | CIDADE: %s | ANO DE FUNDA��O: %d | TREINADOR: %s\n", (i+1), equipes[i].nome, equipes[i].cidade, equipes[i].anoFundacao, equipes[i].treinador );
    }
    
}

void pesquisarEquipe(){
    printf("\n\nINSIRA O NOME DA EQUIPE QUE PROCURA: ");
    char nomePesquisa[100];
    int i;
    getchar();
    fgets(nomePesquisa, sizeof(nomePesquisa), stdin);
    removerQuebraDeLinha(nomePesquisa);
    printf("\n\nRESULTADOS\n\n");
    for ( i = 0; i < totalEquipes; i++)
    {
        if (strcmp(nomePesquisa, equipes[i].nome) == 0)
        {
            printf("ID: %d | NOME: %s | CIDADE: %s | ANO DE FUNDA��O: %d | TREINADOR: %s\n", (i+1), equipes[i].nome, equipes[i].cidade, equipes[i].anoFundacao, equipes[i].treinador );
            
        }
    }
}

void editarEquipe(){
    int id, campo, opcao;
    printf("\n1.Listar todas as equipes\n2.Pesquisar equipe a editar\nINSIRA A OP��O: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        listarEquipes();
        break;
    case 2:
    pesquisarEquipe();
    break;
    default:
        printf("\nOP��O INV�LIDA");
        break;
    }
    printf("DIGITE O C�DIGO DA EQUIPE QUE PRETENDE EDITAR: ");
    scanf("%d", &id);

    if ((id-1) >= totalEquipes)
    {
        printf("\nN�O EXISTE EQUIPE COM ESSE ID");
    }else{
        printf("\n1.NOME\n2.CIDADE\n3.ANO DE FUNDA��O\n4.TREINADOR\n\nDIGITE O N�MERO DO CAMPO QUE DESEJA EDITAR NA EQUIPE %s", equipes[id-1].nome);
        scanf("%d", &campo);
        switch (campo)
        {
        case 1:
            printf("DIGITE O NOVO NOME: ");
            getchar();
            fgets(equipes[id-1].nome, sizeof(equipes[id-1].nome), stdin);
            removerQuebraDeLinha(equipes[id-1].nome);
            printf("O NOVO NOME � %s", equipes[id-1].nome);
            break;
        case 2: 
            printf("DIGITE A NOVA CIDADE: ");
            getchar();
            fgets(equipes[id-1].cidade, sizeof(equipes[id-1].cidade), stdin);
            removerQuebraDeLinha(equipes[id-1].cidade);
            printf("A NOVA CIDADE � %s", equipes[id-1].cidade);
            break;
        case 3: 
            printf("DIGITE O NOVO ANO DE FUNDA��O: ");
            scanf("%d", &equipes[id-1].anoFundacao);
            printf("O ANO ACTUALIZADO � %d",equipes[id-1].anoFundacao );
            break;
        case 4:
            printf("DIGITE O NOVO NOME DO TREINADOR: ");
            fgets(equipes[id-1].treinador, sizeof(equipes[id-1].treinador), stdin);
            removerQuebraDeLinha(equipes[id-1].treinador);
            printf("O NOVO NOME DO TREINADOR � %s", equipes[id-1].treinador);
            break;
        
        default:
            printf("CAMPO INEXISTENTE!");
            break;
        }
    }
    
    
    

}

void eliminarEquipe(){
    int i, id, opcao;
    printf("\n1.Listar todas as equipes\n2.Pesquisar equipe a eliminar\nINSIRA A OP��O: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        listarEquipes();
        break;
    case 2:
    pesquisarEquipe();
    break;
    default:
        printf("\nOP��O INV�LIDA");
        break;
    }
    printf("DIGITE O ID DA EQUIPE QUE DESEJA ELIMINAR: ");
    scanf("%d",&id );
    if ((id-1) >= totalEquipes)
    {
        printf("\nN�O EXISTE EQUIPE COM ESSE ID");
    }else{
        for ( i = id-1; i < totalEquipes; i++)
        {
            equipes[i]= equipes[i+1];
        }

        totalEquipes--;
    }
    
}

//FUN��ES - JOGADORES
void cadastroJogador(){
    
    if (totalEquipes > 0)
    {
        int id, contador;
        jogador player;
        player.golosMarcados = 0;
        printf("SELECIONE A EQUIPE ONDE DESEJA ADICIONAR O JOGADOR\n");
        listarEquipes();
        printf("DIGITE O ID DA EQUIPE ONDE PRETENDE ADICIONAR O JOGADOR: ");
        scanf("%d", &id);
        if ((id-1) >= totalEquipes)
        {
            printf("\nN�O EXISTE EQUIPE COM ESSE ID");
        }else{
            
        
            getchar();
            contador =  equipes[id-1].contadorJogadores;

            if (contador < 30)
            {
                printf("\n\nVAMOS FAZER O CADASTRO DO JOGADOR. PREENCHA AS INFORMA��ES ABAIXO: \n\n");
                printf("NOME: ");
                getchar();
                fgets(player.nome, sizeof(player.nome), stdin);
                removerQuebraDeLinha(player.nome);
                printf("IDADE: ");
                scanf("%d", &player.idade);
                if (player.idade < 16 || player.idade > 40)
                {
                printf("\nIDADE INV�LIDA, ESTE JOAGADOR N�O PODE SER CADASTRADO!\nVoltando � p�gina anterior...");
                return;
                }

                getchar();
                printf("ALTURA: ");
                scanf("%f", &player.altura);
                getchar();
                printf("PESO: ");
                scanf("%f", &player.peso);
                getchar();
                printf("POSI��O: ");
                fgets(player.posicao, sizeof(player.posicao), stdin);
                removerQuebraDeLinha(player.posicao);
                printf("CAMISA: ");
                scanf("%d", &player.camisa);
                getchar();
                strcpy(player.equipeDoJogador,equipes[id-1].nome);

            
                equipes[id-1].jogadores[contador] = player;
                printf("\nNOME: %s | IDADE: %d | ALTURA: %.2f | PESO: %.2f | POSI��O: %s | N� DA CAMISA: %d | EQUIPE: %s | CADASTRO REALIZADO COM SUCESSO!", equipes[id-1].jogadores[contador].nome, equipes[id-1].jogadores[contador].idade, equipes[id-1].jogadores[contador].altura, equipes[id-1].jogadores[contador].peso, equipes[id-1].jogadores[contador].posicao, equipes[id-1].jogadores[contador].camisa, equipes[id-1].jogadores[contador].equipeDoJogador);

                equipes[id-1].contadorJogadores++;

            }else{
                printf("\nESTA EQUIPE J� ATINGIU O LIMITE DE JOGADORES!\n");
                return;
            }
        }
        
     }else{
        printf("\nPARA CADASTRAR UM JOGADOR, PRECISA TER PELO MENOS UMA EQUIPE CADASTRADA.");
        return;
     }
        
}

void listarJogadores(){
    int id, i, contador;

    printf("\nESCOLHA A EQUIPE QUE VOC� DESEJA VER OS JOGADORES\n\n");
    listarEquipes();
    printf("\nDIGITE O ID DA EQUIPE QUE PRETENDE VER OS JOGADORES: ");
    scanf("%d", &id);
    if ((id-1) >= totalEquipes)
    {
        printf("\nN�O EXISTE EQUIPE COM ESSE ID");
        
    }else{
        contador =  equipes[id-1].contadorJogadores;
        for (i = 0; i < contador; i++)

        {
            printf("\n%d.NOME: %s | IDADE: %d | ALTURA: %.2f | PESO: %.2f | POSI��O: %s | N� DA CAMISA: %d | EQUIPE: %s\n", (i+1), equipes[id-1].jogadores[i].nome, equipes[id-1].jogadores[i].idade, equipes[id-1].jogadores[i].altura, equipes[id-1].jogadores[i].peso, equipes[id-1].jogadores[i].posicao, equipes[id-1].jogadores[i].camisa, equipes[id-1].jogadores[i].equipeDoJogador);
        }
            
    }
    
}

void editarJogador(){
    int idEquipe, idJogador, i, contador, campo;
    if (totalEquipes > 0)
    {
        printf("\nESCOLHA A EQUIPE QUE VOC� DESEJA EDITAR O JOGADOR\n\n");
        listarEquipes();
        printf("\nDIGITE O ID DA EQUIPE: ");
        scanf("%d", &idEquipe);
        if ((idEquipe-1) >= totalEquipes)
        {
            printf("\nN�O EXISTE EQUIPE COM ESSE ID");
            
        }else{

            contador =  equipes[idEquipe-1].contadorJogadores;
            for (i = 0; i < contador; i++)

            {
                printf("\nID: %d | NOME: %s | IDADE: %d | EQUIPE: %s\n", (i+1), equipes[idEquipe-1].jogadores[i].nome, equipes[idEquipe-1].jogadores[i].idade,equipes[idEquipe-1].jogadores[i].equipeDoJogador);
            }
            if (equipes[idEquipe-1].contadorJogadores > 0)
            {
                printf("DIGITE O ID DO JOGADOR  QUE VOC� DESEJA EDITAR: ");
                scanf("%d", &idJogador);
                if ((idJogador-1) >= equipes[idEquipe-1].contadorJogadores )
                {
                    printf("\nN�O EXISTE JOGADOR COM ESSE ID");
                    
                }else{

                
                    printf("\nESCOLHA QUAL INFORMA��O VOC� DESEJA EDITAR SOBRE O JOGADOR %s DA EQUIPE %s\n\n1.Nome\n2.Idade\n3.Altura\n4.Peso\n5.Posi��o\n6.N� da camisa\n", equipes[idEquipe-1].jogadores[idJogador-1].nome, equipes[idEquipe-1].nome);
                    scanf("%d", &campo);

                    switch (campo)
                    {
                    case 1:
                        printf("NOVO NOME: ");
                        getchar();
                        fgets(equipes[idEquipe-1].jogadores[idJogador-1].nome, sizeof(equipes[idEquipe-1].jogadores[idJogador-1].nome), stdin);
                        removerQuebraDeLinha(equipes[idEquipe-1].jogadores[idJogador-1].nome);
                        printf("NOME ATUALIZADO: %s", equipes[idEquipe-1].jogadores[idJogador-1].nome);
                        break;
                    case 2:
                        printf("NOVA IDADE: ");
                        scanf("%d", &equipes[idEquipe-1].jogadores[idJogador-1].idade);
                        printf("IDADE ATUALIZADA: %d", equipes[idEquipe-1].jogadores[idJogador-1].idade);
                        break;
                    case 3:
                        printf("NOVA ALTURA: ");
                        scanf("%f", &equipes[idEquipe-1].jogadores[idJogador-1].altura);
                        printf("ALTURA ATUALIZADA: %.2f", equipes[idEquipe-1].jogadores[idJogador-1].altura);
                        break;
                    case 4:
                        printf("NOVO PESO: ");
                        scanf("%f", &equipes[idEquipe-1].jogadores[idJogador-1].peso);
                        printf("PESO ATUALIZADO: %.2f", equipes[idEquipe-1].jogadores[idJogador-1].peso);
                        break;
                    case 5:
                        printf("NOVA POSI��O: ");
                        getchar();
                        fgets(equipes[idEquipe-1].jogadores[idJogador-1].posicao, sizeof(equipes[idEquipe-1].jogadores[idJogador-1].posicao), stdin);
                        removerQuebraDeLinha(equipes[idEquipe-1].jogadores[idJogador-1].posicao);
                        printf("POSI��O ATUALIZADA: %s", equipes[idEquipe-1].jogadores[idJogador-1].posicao);
                        break;
                    case 6:
                        printf("NOVO N� DE CAMISA: ");
                        scanf("%d", &equipes[idEquipe-1].jogadores[idJogador-1].camisa);
                        printf("IDADE ATUALIZADA: %d", equipes[idEquipe-1].jogadores[idJogador-1].camisa);
                        break;
                    default:
                        printf("CAMPO INEXISTENTE!");
                        break;
                    } 
                }
                
            }else{
            printf("\nN�O H� JOGADORES NESTA EQUIPE.");
            return;
                
            }
        }
            
    }else{
        printf("\nN�O FOI POSS�VEL EDITAR JOGADOR.");
        return;
    }
}

void eliminarJogador(){
    int idEquipe, idJogador, contador, i;
    if (totalEquipes > 0)
    {
        printf("\nESCOLHA A EQUIPE ONDE PERTENCE O JOGADOR QUE VOC� DESEJA ELIMINAR\n\n");
        listarEquipes();
        printf("\nDIGITE O ID DA EQUIPE: ");
        scanf("%d", &idEquipe);
        if ((idEquipe-1) >= totalEquipes)
        {
            printf("\nN�O EXISTE EQUIPE COM ESSE ID.");
        }else{
            contador =  equipes[idEquipe-1].contadorJogadores;

            if (contador > 0)
            {
                for (i = 0; i < contador; i++)

                {
                    printf("\nID: %d | NOME: %s | IDADE: %d | EQUIPE: %s", (i+1), equipes[idEquipe-1].jogadores[i].nome, equipes[idEquipe-1].jogadores[i].idade,equipes[idEquipe-1].jogadores[i].equipeDoJogador);
                }

                printf("DIGITE O ID DO JOGADOR  QUE VOC� DESEJA ELIMINAR: ");
                scanf("%d", &idJogador);
                if ((idJogador-1) >= contador)
                {
                    printf("\nN�O EXISTE JOGADOR COM ESSE ID NESTA EQUIPE.");
                }else{                
                    for ( i = idJogador-1; i < contador; i++)
                    {
                        equipes[idEquipe-1].jogadores[i]= equipes[idEquipe-1].jogadores[i+1];
                    }
                    equipes[idEquipe-1].contadorJogadores--;
                }
                
            }else{
                printf("\nN�O H� JOGADORES NESTA EQUIPE.");
            }
        }
        
        }else{
            printf("\nN�O � POSS�VEL ELIMINAR JOGADOR.");
        }
    
}

void moverJogador(){
    int idEquipeInicial, idEquipeDestino, idJogador, contador1, contador2, i;
    if (totalEquipes > 0)
    {
        printf("\nESCOLHA A EQUIPE ONDE PERTENCE O JOGADOR QUE VOC� DESEJA MOVER\n\n");
        listarEquipes();
        printf("\nDIGITE O ID DA EQUIPE: ");
        scanf("%d", &idEquipeInicial);
        if ((idEquipeInicial-1) >= 0)
        {
            printf("\nN�O EXISTE EQUIPE COM ESSE ID.");
        }else{
        
            contador1 =  equipes[idEquipeInicial-1].contadorJogadores;
            if (contador1 > 0)
            {
                for (i = 0; i < contador1; i++)
                {
                    printf("\nID: %d | NOME: %s | IDADE: %d | EQUIPE: %s\n", (i+1), equipes[idEquipeInicial-1].jogadores[i].nome, equipes[idEquipeInicial-1].jogadores[i].idade,equipes[idEquipeInicial-1].jogadores[i].equipeDoJogador);
                }

                printf("DIGITE O ID DO JOGADOR  QUE VOC� DESEJA MOVER: ");
                scanf("%d", &idJogador);
                printf("\nPARA QUE EQUIPE DESEJA MOVER O JOGADOR %s?", equipes[idEquipeInicial-1].jogadores[i].nome);
                listarEquipes();
                printf("\nDIGITE O ID:");
                scanf("%d", &idEquipeDestino);
                if (idEquipeDestino == idEquipeInicial)
                {
                    printf("\nESTE JOGADOR J� FAZ PARTE DESSA EQUIPE.");
                }else{

                    contador2 =  equipes[idEquipeDestino-1].contadorJogadores;
                    equipes[idEquipeDestino-1].jogadores[contador2] = equipes[idEquipeInicial-1].jogadores[idJogador-1];
                    equipes[idEquipeDestino-1].contadorJogadores++;

                    for ( i = idJogador-1; i < contador1; i++)
                    {
                        equipes[idEquipeInicial-1].jogadores[i]= equipes[idEquipeInicial-1].jogadores[i+1];
                    }
                    equipes[idEquipeInicial-1].contadorJogadores--;
                    printf("\nO jogador %s foi movido da equipe %s para a equipe %s.\n",equipes[idEquipeDestino-1].jogadores[i].nome, equipes[idEquipeInicial-1].nome, equipes[idEquipeDestino-1].nome );
                }
            }else{
                printf("\nA EQUIPE SELECIONADA N�O POSSUI JOGADORES PARA MOVER.");
                return;
            }

        }
    
    }else {
        printf("\nN�O � POSS�VEL MOVER JOGADORES POIS N�O H� EQUIPES CADASTRADAS.");
        return;
    }
   
}

//FUN��ES - CAMPEONATOS

void cadastrarCampeonato(){
    
    if (totalCampeonatos < 10)
    {
        campeonato novoCampeonato;
        novoCampeonato.numPartidas = 0;
        int i, contador, idEquipe;

        printf("\nBEM-VINDO(A) � SECC��O DE CADASTRO DE CAMPEONATOS, PREENCHA AS INFORMA��ES ABAIXO SOBRE O CAMPEONATO\n");
        printf("NOME: ");
        getchar();
        fgets(novoCampeonato.nome, sizeof(novoCampeonato.nome), stdin);
        removerQuebraDeLinha(novoCampeonato.nome);
        printf("ANO DE REALIZA��O: ");
        scanf("%d", &novoCampeonato.ano);

        do
        {
            printf("\nN� DE EQUIPES QUE V�O PARTICIPAR(ENTRE 4 E 20): ");
            scanf("%d", &novoCampeonato.numEquipes);
            if (novoCampeonato.numEquipes < 4)
            {
                printf("\nO n�mero de equipes por campeonato n�o pode ser inferior a 4.");
            }else if (novoCampeonato.numEquipes > 20)
            {
                printf("\nO n�mero de equipes por campeonato n�o pode ser superior a 20.");
            }
            
        } while (novoCampeonato.numEquipes < 4 || novoCampeonato.numEquipes > 20);
        
        contador = novoCampeonato.numEquipes;
        for (i = 0; i < contador; i++)
        {
            printf("\nESCOLHA A EQUIPE %d DO CAMPEINATO\n", (i+1));
            listarEquipes();
            printf("DIGITE O ID DA EQUIPE: ");
            scanf("%d", &idEquipe);
            getchar();
            novoCampeonato.equipesParticipantes[i] = equipes[idEquipe-1];
            printf("\nEquipe %s registada no campeonato %s com sucesso.\n",novoCampeonato.equipesParticipantes[i].nome, novoCampeonato.nome );
        }

        campeonatos[totalCampeonatos] = novoCampeonato;
        totalCampeonatos++;
        printf("\nCampeonato %s registado com sucesso.\n", campeonatos[totalCampeonatos-1].nome);

    }else{
        printf("\nN�O � POSS�VEL CADASTRAR NOVO CAMPEONATO POIS O LIMITE FOI ATINGIDO.");
    }
    
    
}

void listarCampeonatos(){
    int i;
    printf("\n\t\t\tLISTA DE CAMPEONATOS\n");
    for ( i = 0; i < totalCampeonatos; i++)
    {
        printf("Id: %d | Nome: %s | Ano: %d | Campe�o: %s\n\n",(i+1) ,campeonatos[i].nome, campeonatos[i].ano,campeonatos[i].campeao.nome );
    }
    
}

void listarEquipesCampeonato(){
    int idCampeonato, i;
    printf("\nESCOLHA O CAMPEONATO: \n");
    listarCampeonatos();
    printf("\nDigite o Id do campeonato: ");
    scanf("%d", &idCampeonato);
    for ( i = 0; i < campeonatos[idCampeonato-1].numEquipes; i++)
    {
        printf("\nId: %d | Nome: %s", (i+1), campeonatos[idCampeonato-1].equipesParticipantes[i].nome);
    }
    
}

void listarPartidasCampeonato(){
    int idCampeonato, i;
    printf("\nESCOLHA O CAMPEONATO: \n");
    listarCampeonatos();
    printf("\nDigite o Id do campeonato: ");
    scanf("%d", &idCampeonato);

    for (i = 0; i < campeonatos[idCampeonato-1].numPartidas; i++)
    {
        printf("\n%d.%s (%d) VS %s (%d) | VENCEDOR: %s", (i+1), campeonatos[idCampeonato-1].partidas[i].equipe1.nome, campeonatos[idCampeonato-1].partidas[i].golosEquipe1 ,campeonatos[idCampeonato-1].partidas[i].equipe2.nome, campeonatos[idCampeonato-1].partidas[i].golosEquipe2, campeonatos[idCampeonato-1].partidas[i].vencedor.nome );
    }
    
}

void editarCampeonato(){
    int idCampeonato, campo;
    if (totalCampeonatos > 0)
    {
        listarCampeonatos();
        printf("\n\nInsira o ID do campeonato que deseja editar: ");
        scanf("%d", &idCampeonato);
        printf("\nNOME: %s | ANO: %d\n\n1.Nome\n2.Ano\nINSIRA O CAMPO QUE DESEJA EDITAR: ", campeonatos[idCampeonato-1].nome, campeonatos[idCampeonato-1].ano);
        scanf("%d", &campo);
        switch (campo)
        {
        case 1:
            printf("\n\nNOVO NOME: ");
            getchar();
            fgets(campeonatos[idCampeonato-1].nome, sizeof(campeonatos[idCampeonato-1].nome), stdin);
            removerQuebraDeLinha(campeonatos[idCampeonato-1].nome);
            printf("\nACTUALIZA��O: \nNOME: %s | ANO: %d", campeonatos[idCampeonato-1].nome, campeonatos[idCampeonato-1].ano);
            break;
        case 2:
            printf("\n\nNOVO ANO: ");
            scanf("%d", &campeonatos[idCampeonato-1].ano);
            printf("\nACTUALIZA��O: \nNOME: %s | ANO: %d", campeonatos[idCampeonato-1].nome, campeonatos[idCampeonato-1].ano);
            break;
        
        default:
            printf("\nCAMPO INEXISTENTE");
            break;
        }
    }else{
        printf("\nN�O H� CAMPEONATOS PARA EDITAR");
    }
    

}

void encerrarCampeonato(){
    int idCampeonato, i, maiorPontuacao, idVencedor;
    campeonato campAEncerrar;
    printf("\nESCOLHA O CAMPEONATO: \n");
    listarCampeonatos();
    printf("\nDigite o Id do campeonato: ");
    scanf("%d", &idCampeonato);
    campAEncerrar = campeonatos[idCampeonato-1];
    if (campAEncerrar.numPartidas > 0)
    {
        maiorPontuacao = campAEncerrar.equipesParticipantes[0].pontos;
        idVencedor = 0;
        for ( i = 1; i < campAEncerrar.numEquipes; i++)
        {
            if (campAEncerrar.equipesParticipantes[i].pontos > maiorPontuacao)
            {
                maiorPontuacao = campAEncerrar.equipesParticipantes[i].pontos;
                idVencedor = i;
            }
            
        }
        campAEncerrar.campeao = campAEncerrar.equipesParticipantes[idVencedor];
    }else {
        printf("\nESTE CAMPEONATO AINDA N�O PODE SER ENCERRADO POIS N�O TEVE NENHUMA PARTIDA.");
    }
    
}

void eliminarCampeonato(){
    int i, id;
    listarCampeonatos();
    printf("DIGITE O ID DO CAMPEONATO QUE DESEJA ELIMINAR: ");
    scanf("%d",&id );
    if ((id-1) >= totalCampeonatos)
    {
        printf("\nN�O EXISTE CAMPEONATO COM ESSE ID");
    }else{
            for ( i = id-1; i < totalCampeonatos; i++)
            {
                campeonatos[i]= campeonatos[i+1];
            }

            totalCampeonatos--;
        }
}

//FUN��ES - PARTIDAS
void cadastrarPartida(){
    int idEquipe1, idEquipe2, idCampeonato, i;
    partida novaPartida; 
    novaPartida.golosEquipe1 = 0;
    novaPartida.golosEquipe2 = 0;
    printf("\nESCOLHA O CAMPEONATO: \n");
    listarCampeonatos();
    printf("\nDigite o ID do campeonato: ");
    scanf("%d", &idCampeonato);
    for ( i = 0; i < campeonatos[idCampeonato-1].numEquipes; i++)
    {
        printf("\nId: %d | Nome: %s", (i+1), campeonatos[idCampeonato-1].equipesParticipantes[i].nome);
    }
    printf("\nDigite o ID da Equipe 1: ");
    scanf("%d", &idEquipe1);
    novaPartida.equipe1 = campeonatos[idCampeonato-1].equipesParticipantes[idEquipe1-1];

    printf("\nDigite o ID da Equipe 2: ");
    getchar();
    scanf("%d", &idEquipe2);
    novaPartida.equipe2 = campeonatos[idCampeonato-1].equipesParticipantes[idEquipe2-1];
    
    printf("\nInsira a data do jogo (Ex: 01/01/2000): ");
    getchar();
    fgets(novaPartida.data, sizeof(novaPartida.data), stdin);
    removerQuebraDeLinha(novaPartida.data);
    printf("\nInsira o local da partida: ");
    getchar();
    fgets(novaPartida.local, sizeof(novaPartida.local), stdin);
    removerQuebraDeLinha(novaPartida.local);

    printf("\nINSIRA O N�MERO DE GOLOS DA EQUIPE %s: ", novaPartida.equipe1.nome);
    scanf("%d", &novaPartida.golosEquipe1);

    printf("\nINSIRA O N�MERO DE GOLOS DA EQUIPE %s: ", novaPartida.equipe2.nome);
    scanf("%d", &novaPartida.golosEquipe2);

    if (novaPartida.golosEquipe1 > novaPartida.golosEquipe2)
    {
        novaPartida.equipe1.pontos+=3;
        strcpy(novaPartida.vencedor.nome, novaPartida.equipe1.nome);
    } else if (novaPartida.golosEquipe1 < novaPartida.golosEquipe2)
    {
        novaPartida.equipe2.pontos+=3;
        strcpy(novaPartida.vencedor.nome, novaPartida.equipe2.nome);
    }else{
        novaPartida.equipe1.pontos+=1;
        novaPartida.equipe2.pontos+=2;
        strcpy(novaPartida.vencedor.nome, "EMPATE!");
    }
    
    campeonatos[idCampeonato-1].partidas[campeonatos[idCampeonato-1].numPartidas] = novaPartida;
    campeonatos[idCampeonato-1].numPartidas++;

    printf("\nPartida: %s VS %s registada no campeonato %s\n Data: %s\nLocal: %s\nVencedor: %s", campeonatos[idCampeonato-1].partidas[campeonatos[idCampeonato-1].numPartidas-1].equipe1.nome, campeonatos[idCampeonato-1].partidas[campeonatos[idCampeonato-1].numPartidas-1].equipe2.nome, campeonatos[idCampeonato-1].nome, campeonatos[idCampeonato-1].partidas[campeonatos[idCampeonato-1].numPartidas-1].data, campeonatos[idCampeonato-1].partidas[campeonatos[idCampeonato-1].numPartidas-1].local, campeonatos[idCampeonato-1].partidas[campeonatos[idCampeonato-1].numPartidas-1].vencedor.nome);
}

//FUN��O PRINCIPAL
int main() {
    setlocale(LC_ALL, "Portuguese");
    int operacao, opcaoConsulta, opcaoConsultarEquipes, opcaoConsultaCampeonatos, opcaoAdm, opcaoCadastro, opcaoEditar, opcaoEliminar, opcaoEditarCampeonato;

    do{
        printf("\t\t\t\t\t FAF - Federa��o Angolana de Futebol \n\n\n");
        printf("\t\t\t\tBEM-VINDO(A) AO SISTEMA DE INFORMA��O DA FAF!\n");
        printf("\t\t\tConsulte e cadastre equipes, jogadores, campeonatos, partidas e muito mais!\n\n\n");
        printf("O QUE DESEJA FAZER? \n\n1.Consultar informa��o\n2.Entrar como Administrador\n0. Sair");
        printf("\nDIGITE O N�MERO CORRESPONDENTE A OPERA��O: ");
        scanf("%d", &operacao);
        switch (operacao)
        {
        case 1://Consultar informa��es
            system("cls");
            printf("\nO QUE DESEJA CONSULTAR?\n1.Equipes\n2.Jogadores\n3.Campeonatos e Partidas\n\nDIGITE O N�MERO DA OP��O: ");
            scanf("%d", &opcaoConsulta);
            switch (opcaoConsulta)
            {
            case 1: //Consultar Equipes
                system("cls");
                printf("\nCONSULTAR EQUIPES\n\n1.Listar todas as equipes\n2.Pesquisar equipe\nESCOLHA UMA DAS OP��ES ACIMA: ");
                scanf("%d", &opcaoConsultarEquipes);
                switch (opcaoConsultarEquipes)
                {
                case 1:
                    system("cls");
                    listarEquipes();
                    break;
                case 2:
                    system("cls");
                    pesquisarEquipe();
                    break;
                default:
                    printf("\nOP��O INV�LIDA\n");
                    break;
                }
                break;
            case 2:
                system("cls");
                printf("\nCONSULTAR JOGADOES\n\n");
                listarJogadores();
                break;
            case 3:
                system("cls");
                printf("\nCAMPEONATOS E PARTIDAS\n\nO QUE DESEJA CONSULTAR?\n1.Listar todos os campeonatos\n2.Listar Equipes de um campeonato\n3.Listar partidas de um campeonato\n\nESCOLHA UMA DAS OP��ES ACIMA: ");
                scanf("%d", &opcaoConsultaCampeonatos);
                switch (opcaoConsultaCampeonatos)
                {
                case 1:
                    system("cls");
                    listarCampeonatos();
                    break;
                case 2:
                    listarEquipesCampeonato();
                    break;
                case 3:
                    listarPartidasCampeonato();
                    break;
                default:
                    printf("\nOP��O INV�LIDA\n");
                    break;
                }
                break;
            default:
                printf("\nOP��O INV�LIDA\n");
                break;
            }

            break;
        case 2://FAZER LOGIN
            system("cls");
            if (login())
            {
                system("cls");
                do
                {
                    printf("\n\nBEM-VINDO � CONTA ADMINISTRADOR! O QUE DESEJA FAZER?\n\n1.Consultar informa��es\n2.Cadastrar\n3.Editar\n4.Eliminar\n0.Terminar Sess�o\n\n");
                    scanf("%d", &opcaoAdm);
                    switch (opcaoAdm)
                    {
                    case 1:
                         system("cls");
                        printf("\nO QUE DESEJA CONSULTAR?\n1.Equipes\n2.Jogadores\n3.Campeonatos e Partidas\n\nDIGITE O N�MERO DA OP��O: ");
                        scanf("%d", &opcaoConsulta);
                        switch (opcaoConsulta)
                        {
                        case 1: //Consultar Equipes
                            system("cls");
                            printf("\nCONSULTAR EQUIPES\n\n1.Listar todas as equipes\n2.Pesquisar equipe\nESCOLHA UMA DAS OP��ES ACIMA: ");
                            scanf("%d", &opcaoConsultarEquipes);
                            switch (opcaoConsultarEquipes)
                            {
                            case 1:
                                system("cls");
                                listarEquipes();
                                break;
                            case 2:
                                system("cls");
                                pesquisarEquipe();
                                break;
                            default:
                                printf("\nOP��O INV�LIDA\n");
                                break;
                            }
                            break;
                        case 2:
                            system("cls");
                            printf("\nCONSULTAR JOGADOES\n\n");
                            listarJogadores();
                            break;
                        case 3:
                            system("cls");
                            printf("\nCAMPEONATOS E PARTIDAS\n\nO QUE DESEJA CONSULTAR?\n1.Listar todos os campeonatos\n2.Listar Equipes de um campeonato\n3.Listar partidas de um campeonato\n\nESCOLHA UMA DAS OP��ES ACIMA: ");
                            scanf("%d", &opcaoConsultaCampeonatos);
                            switch (opcaoConsultaCampeonatos)
                            {
                            case 1:
                                system("cls");
                                listarCampeonatos();
                                break;
                            case 2:
                                listarEquipesCampeonato();
                                break;
                            case 3:
                                listarPartidasCampeonato();
                                break;
                            default:
                                printf("\nOP��O INV�LIDA\n");
                                break;
                            }
                            break;
                        default:
                            printf("\nOP��O INV�LIDA\n");
                            break;
                        }
                            break;
                    case 2:
                        system("cls");
                        printf("\nO QUE DESEJA CADASTRAR?\n\n1.Equipes\n2.Jogador\n3.Campeonato\n4.Partida\n");
                        scanf("%d", &opcaoCadastro);
                        switch (opcaoCadastro)
                        {
                        case 1:
                            system("cls");
                            cadastroEquipe();
                            break;
                        case 2:
                            system("cls");
                            cadastroJogador();
                            break;
                        case 3:
                            system("cls");
                            if (totalEquipes >= 4)
                            {
                               cadastrarCampeonato();
                            }else{
                                printf("\nANTES DE CADASTRAR UM CAMPEONATO, DEVE TER PELO MENOS 4 EQUIPES CADASTRADAS.\n");
                                break;
                            }
                            break;
                        case 4:
                            system("cls");
                            if (totalCampeonatos > 0)
                            {
                                cadastrarPartida();
                            }else{
                                printf("\nANTES DE CADASTRAR UMA PARTIDA, DEVE TER PELO MENOS 1 CAMPEONATO CADASTRADO.\n");
                                break;
                            }
                            break;
                        default:
                            printf("\nOP��O INV�LIDA!\n\n");
                            break;
                        }
                        break;
                    case 3:
                        system("cls");
                        printf("\nO QUE DESEJA EDITAR?\n\n1.Editar equipe\n2.Editar jogador\n3.Mover Jogador\n4.Editar campeonato\n5.Editar partida\nESCOLHA UMA DAS OP��ES ACIMA: ");
                        scanf("%d", &opcaoEditar);
                        switch (opcaoEditar)
                        {
                        case 1:
                            if (totalEquipes > 0)
                            {
                                system("cls");
                                editarEquipe();
                            }else{
                                printf("\nN�O H� EQUIPES PARA EDITAR.\n");
                                break;
                            }
                            break;
                        case 2:
                            editarJogador();
                            break;
                        case 3:
                            moverJogador();
                            break;
                        case 4:
                            system("cls");
                            printf("\n\n1.Editar campeonato\n2.Encerrar campeonato");
                            scanf("%d", &opcaoEditarCampeonato);
                            switch (opcaoEditarCampeonato)
                            {
                            case 1:
                                editarCampeonato();
                                break;
                            case 2:
                                if (totalCampeonatos > 0)
                                {
                                    printf("\nFUNCIONALIDADE EM DESENVOLVIMENTO...");
                                    //encerrarCampeonato();
                                }else{
                                    printf("N�O H� CAMPEONATOS PARA ENCERRAR.");
                                    break;
                                }
                                
                                break;
                            
                            default:
                                printf("\nOP��O INV�LIDA!\n\n");
                                break;
                            }
                            break;
                        case 5:
                            printf("\nFUNCIONALIDADE EM DESENVOLVIMENTO...");
                            
                            break;
                        default:
                            printf("\nOP��O INV�LIDA!\n\n");
                            break;
                        }
                        break;
                    case 4:
                        system("cls");
                        printf("\nO QUE DESEJA ELIMINAR?\n\n1.Eliminar equipe\n2.Eliminar jogador\n3.Eliminar campeonato\n4.Eliminar partida\nESCOLHA UMA DAS OP��ES ACIMA: ");
                        scanf("%d", &opcaoEliminar);
                        switch (opcaoEliminar)
                        {
                        case 1:
                            if (totalEquipes > 0)
                            {
                                system("cls");
                                eliminarEquipe();
                            }else{
                                printf("\nN�O H� EQUIPES PARA ELIMINAR.\n");
                                break;
                            }
                            break;
                        case 2:
                            eliminarJogador();
                            break;
                        case 3:
                            eliminarCampeonato();
                            break;
                        case 4:
                            printf("\nFUNCIONALIDADE EM DESENVOLVIMENTO...");
                            break;
                        default:
                            printf("\nOP��O INV�LIDA!\n\n");
                            break;
                        }
                        break;
                        break;
                    case 0:
                        printf("\nTERMINANDO SESS�O...");
                    default:
                        printf("\nOPERA��O INV�LIDA!\n\n");
                        break;
                    }
                } while (opcaoAdm !=0);
                
            }else{
                break;
            }
            break;
        case 0: 
            printf("\n\nENCERRANDO...");
            break;
        
        default:
            printf("\nOPERA��O INV�LIDA!\n\n");
            break;
        }

 }while (operacao != 0);

   
}