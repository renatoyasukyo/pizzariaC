#include <stdio.h>
#include <string.h>

// 4 structs definidas
typedef struct
{
    int telefone;
    char nome_cliente[100];
    char endereco[200];
} Cliente;

typedef struct
{
    int codigo_pizza;
    char nome_pizza[100];
    float valor;
    char descricao[200];
} Pizza;

typedef struct
{
    int numero_pedido;
    int numero_cliente;
    int codigo_pizza;
    int codigo_entregador;
    int situacao;
    int avaliacao;
} Pedido;

typedef struct
{
    int cod_entregador;
    int num_entregas;
    int em_rota;
} Entregador;

void cadastrar_pizzas(Pizza *pizzas, int *num_pizzas)
{ // funcao (pizzaria) que cadastra uma pizza em uma variável usando a struct Pizza
    if (*num_pizzas >= 100)
    {
        printf("Limite maximo de pizzas cadastradas atingido.\n");
        return;
    }

    int codigo;
    do
    {
        printf("Digite o codigo da pizza: ");
        scanf("%d", &codigo);

        int i;
        for (i = 0; i < *num_pizzas; i++)
        {
            if (pizzas[i].codigo_pizza == codigo)
            {
                printf("Codigo de pizza ja existente. Digite outro codigo.\n");
                codigo = -1; //-1 indica código inválido, poderia ser qualquer outro valor
                break;
            }
        }
    } while (codigo == -1);

    pizzas[*num_pizzas].codigo_pizza = codigo;

    printf("Digite o nome da pizza: ");
    scanf(" %[^\n]s", pizzas[*num_pizzas].nome_pizza);
    printf("Digite o valor da pizza: ");
    scanf("%f", &pizzas[*num_pizzas].valor);
    printf("Digite uma descrição da pizza: ");
    scanf(" %[^\n]s", pizzas[*num_pizzas].descricao);

    (*num_pizzas)++;

    printf("Pizza cadastrada com sucesso!\n");
}

void alterar_dados_pizza(Pizza *pizzas, int *num_pizzas)
{ // funcao (pizzaria) que modifica os dados de uma pizza já cadastrada anteriormente
    int opcao;

    do
    {
        printf("Digite a opcao de busca:\n");
        printf("1. Buscar por código da pizza\n");
        printf("2. Buscar por nome da pizza\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            int codigo;
            printf("Digite o código da pizza que deseja alterar: ");
            scanf("%d", &codigo);

            for (int i = 0; i < *num_pizzas; i++)
            {
                if (pizzas[i].codigo_pizza == codigo)
                {
                    printf("Digite o novo nome da pizza: ");
                    scanf(" %[^\n]s", pizzas[i].nome_pizza);

                    printf("Digite o novo valor da pizza: ");
                    scanf("%f", &pizzas[i].valor);

                    printf("Digite a nova descrição da pizza: ");
                    scanf(" %[^\n]s", pizzas[i].descricao);

                    printf("Dados da pizza alterados com sucesso!\n");
                    return;
                }
            }

            printf("Código de pizza inválido.\n");
        }
        else if (opcao == 2)
        {
            char nome[100];
            printf("Digite o nome da pizza que deseja alterar: ");
            scanf(" %[^\n]s", nome);

            for (int i = 0; i < *num_pizzas; i++)
            {
                if (strcmp(pizzas[i].nome_pizza, nome) == 0)
                {
                    printf("Digite o novo código da pizza: ");
                    scanf("%d", &pizzas[i].codigo_pizza);

                    printf("Digite o novo valor da pizza: ");
                    scanf("%f", &pizzas[i].valor);

                    printf("Digite a nova descrição da pizza: ");
                    scanf(" %[^\n]s", pizzas[i].descricao);

                    printf("Dados da pizza alterados com sucesso!\n");
                    return;
                }
            }

            printf("Nome de pizza inválido.\n");
        }
        else
        {
            printf("Opcao inválida. Por favor, selecione uma opcao válida.\n");
        }
    } while (1);
}

void remover_pizza(Pizza *pizzas, int *num_pizzas)
{// função (pizzaria) que remove uma pizza já cadastrada
    int codigo;
    printf("Digite o codigo da pizza que deseja remover: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < *num_pizzas; i++)
    {
        if (pizzas[i].codigo_pizza == codigo)
        {
            pizzas[i].codigo_pizza = 0;
            (*num_pizzas)--;
            printf("Pizza removida com sucesso!\n");
            return;
        }
    }

    printf("Codigo de pizza invalido.\n");
}

void cadastrar_cliente(Cliente *clientes, int *num_clientes)
{//função (cliente) que cadastra um cliente novo
    if (*num_clientes >= 1000)
    {
        printf("Limite máximo de clientes cadastrados atingido.\n");
        return;
    }

    printf("Cadastrar cliente:\n");
    printf("Digite o numero de telefone do cliente: ");
    scanf("%d", &clientes[*num_clientes].telefone);
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", clientes[*num_clientes].nome_cliente);
    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]s", clientes[*num_clientes].endereco);

    (*num_clientes)++;

    printf("Cliente cadastrado com sucesso!\n");
}

void alterar_dados_cliente(Cliente *clientes, int *num_clientes)
{//função (cliente) que altera dados de um cliente já existente
    int opcao;

    do
    {
        printf("Digite a opcao de busca:\n");
        printf("1. Buscar por número de telefone\n");
        printf("2. Buscar por nome de cliente\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            int telefone;
            printf("Digite o número de telefone do cliente que deseja alterar: ");
            scanf("%d", &telefone);

            for (int i = 0; i < *num_clientes; i++)
            {
                if (clientes[i].telefone == telefone)
                {
                    printf("Digite o novo nome do cliente: ");
                    scanf(" %[^\n]s", clientes[i].nome_cliente);

                    printf("Digite o novo endereço do cliente: ");
                    scanf(" %[^\n]s", clientes[i].endereco);

                    printf("Dados do cliente alterados com sucesso!\n");
                    return;
                }
            }

            printf("Número de telefone inválido.\n");
        }
        else if (opcao == 2)
        {
            char nome[100];
            printf("Digite o nome do cliente que deseja alterar: ");
            scanf(" %[^\n]s", nome);

            for (int i = 0; i < *num_clientes; i++)
            {
                if (strcmp(clientes[i].nome_cliente, nome) == 0)
                {
                    printf("Digite o novo número de telefone do cliente: ");
                    scanf("%d", &clientes[i].telefone);

                    printf("Digite o novo endereço do cliente: ");
                    scanf(" %[^\n]s", clientes[i].endereco);

                    printf("Dados do cliente alterados com sucesso!\n");
                    return;
                }
            }

            printf("Nome de cliente inválido.\n");
        }
        else
        {
            printf("Opcao inválida. Por favor, selecione uma opcao valida.\n");
        }
    } while (1);
}

void remover_conta(Cliente *clientes, int *num_clientes)
{//função (cliente) que deleta a conta de um cliente cadastrado
    int telefone;
    printf("Digite o numero de telefone do cliente que deseja remover: ");
    scanf("%d", &telefone);

    for (int i = 0; i < *num_clientes; i++)
    {
        if (clientes[i].telefone == telefone)
        {
            for (int j = i; j < *num_clientes - 1; j++)
            {
                clientes[j] = clientes[j + 1];
            }

            (*num_clientes)--;
            printf("Conta removida com sucesso!\n");
            return;
        }
    }

    printf("Numero de telefone invalido. Nenhuma conta removida.\n");
}

void ver_menu_pizzas(Pizza *pizzas, int *num_pizzas)
{//função (cliente) que mostra todas as pizzas cadastradas
    printf("Menu de Pizzas:\n");

    if (*num_pizzas == 0)
    {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    for (int i = 0; i < *num_pizzas; i++)
    {
        printf("Codigo: %d\n", pizzas[i].codigo_pizza);
        printf("Nome: %s\n", pizzas[i].nome_pizza);
        printf("Valor: R$ %.2f\n", pizzas[i].valor);
        printf("Descricao: %s\n\n", pizzas[i].descricao);
    }
}

void fazer_pedido(Pedido pedidos[], int *num_pedidos, Cliente clientes[], int *num_clientes, Pizza pizzas[], int *num_pizzas)
{//função (cliente) de fazer pedido
    int numero_pedido = *num_pedidos;
    int numero_cliente;
    int codigo_pizza;
    int avaliacao = 0;
    int situacao_pedido = 1;

    printf("---- Fazer Pedido ----\n");
    printf("Numero do Cliente: ");
    scanf("%d", &numero_cliente);

    int cliente_cadastrado = 0;
    for (int i = 0; i < *num_clientes; i++)
    {
        if (clientes[i].telefone == numero_cliente)
        {
            cliente_cadastrado = 1;
            break;
        }
    }

    if (!cliente_cadastrado)
    {
        printf("Cliente nao cadastrado.\n");
        return;
    }

    printf("Codigo da Pizza pedida: ");
    scanf("%d", &codigo_pizza);

    int pizza_cadastrada = 0;
    for (int i = 0; i < *num_pizzas; i++)
    {
        if (pizzas[i].codigo_pizza == codigo_pizza)
        {
            pizza_cadastrada = 1;
            break;
        }
    }

    if (!pizza_cadastrada)
    {
        printf("Pizza nao cadastrada.\n");
        return;
    }

    pedidos[*num_pedidos].numero_pedido = numero_pedido + 1;
    pedidos[*num_pedidos].numero_cliente = numero_cliente;
    pedidos[*num_pedidos].codigo_pizza = codigo_pizza;
    pedidos[*num_pedidos].avaliacao = avaliacao;
    pedidos[*num_pedidos].situacao = situacao_pedido;

    (*num_pedidos)++;

    printf("Pedido %d realizado com sucesso!\n", numero_pedido + 1);
}

void recebimento_pedido(Pedido pedidos[], int *num_pedidos, Entregador *entregadores)
{//função (cliente) para indicar recebimento do pedido
    int numero_pedido;

    printf("---- Recebimento do Pedido ----\n");

    printf("Numero do Pedido: ");
    scanf("%d", &numero_pedido);

    int pedido_feito = 0;
    for (int i = 0; i < *num_pedidos; i++)
    {
        if (pedidos[i].numero_pedido == numero_pedido)
        {
            pedido_feito = 1;
            if (pedidos[i].situacao == 3)
            {
                printf("Este pedido ja foi entregue e foi avaliado em: %d\n", pedidos[i].avaliacao);
            }
            else if (pedidos[i].situacao == 1)
            {
                printf("Este pedido nao foi despachado ainda.\n");
            }
            else
            {
                entregadores[pedidos[i].codigo_entregador].em_rota = 0;
                pedidos[i].situacao = 3;
                printf("Pedido recebido com sucesso!\n");

                int avaliacao;
                do
                {
                    printf("Avalie o pedido (de 1 a 5): ");
                    scanf("%d", &avaliacao);

                    if (avaliacao < 1 || avaliacao > 5)
                    {
                        printf("Avaliacao invalida. A avaliacao deve ser um valor entre 1 e 5.\n");
                    }
                } while (avaliacao < 1 || avaliacao > 5);

                pedidos[i].avaliacao = avaliacao;

                printf("Avaliacao registrada com sucesso!\n");
                return;
            }
        }
        if (!pedido_feito)
        {
            printf("Pedido nao encontrado.\n");
        }
    }
}

void despacho_pizza(Pedido *pedidos, int *num_pedidos, Entregador *entregadores)
{//função (pizzaria) para indicar que a pizza foi despachada
    printf("---- Despacho da Pizza ----\n");

    // Verificar disponibilidade de entregadores
    int entregador_disponivel = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (entregadores[i].em_rota == 0)
        {
            entregador_disponivel = 1;
            break;
        }
    }

    if (!entregador_disponivel)
    {
        printf("Não há entregadores disponíveis no momento.\n");
        return;
    }

    printf("Lista de pedidos em preparo:\n");
    int pedido_em_preparo = 0;
    for (int i = 0; i < *num_pedidos; i++)
    {
        if (pedidos[i].situacao == 1)
        {
            pedido_em_preparo = 1;
            printf("Numero do Pedido: %d\n", pedidos[i].numero_pedido);
            printf("Cliente: %d\n", pedidos[i].numero_cliente);
            printf("Pizza: %d\n", pedidos[i].codigo_pizza);
            printf("-------------------------\n");
        }
    }

    if (!pedido_em_preparo)
    {
        printf("Nenhum pedido em preparo encontrado.\n");
        return;
    }

    int numero_pedido_selecionado;
    printf("Digite o numero do pedido que deseja despachar: ");
    scanf("%d", &numero_pedido_selecionado);

    int pedido_valido = 0;
    int entregador_selecionado = 0;

    for (int i = 0; i < *num_pedidos; i++)
    {
        if (pedidos[i].numero_pedido == numero_pedido_selecionado && pedidos[i].situacao == 1)
        {
            for (int j = 1; j <= 10; j++)
            {
                if (entregadores[j].em_rota == 0)
                {
                    entregador_selecionado = j;
                    pedidos[i].codigo_entregador = entregador_selecionado;
                    entregadores[entregador_selecionado].num_entregas++;
                    entregadores[entregador_selecionado].em_rota = 1;
                    pedido_valido = 1;
                    break;
                }
            }

            if (pedido_valido)
            {
                pedidos[i].situacao = 2;
                printf("Pedido despachado com sucesso! Entregador numero %d\n", entregador_selecionado);
            }
            else
            {
                printf("Não há entregadores disponíveis no momento.\n");
            }

            break;
        }
    }

    if (!pedido_valido)
    {
        printf("Numero de pedido invalido. Selecione um pedido valido da lista.\n");
    }
}

void exibir_entregadores(Entregador *entregadores)
{//função (pizzaria) que mostra os entregadores disponíveis e quantas entregas cada um fez
    printf("---- Exibir Entregadores ----\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("Entregador %d\n", i);
        printf("Entregas feitas: %d\n", entregadores[i].num_entregas);
        printf("-------------------------\n");
    }
}

float somar_vendas(int *num_pedidos, Pizza pizzas[])
{//função (pizzaria) que mostra o montante adquirido pelas vendas
    float total_vendas = 0.0;

    for (int i = 0; i < *num_pedidos; i++)
    {
        total_vendas += *num_pedidos * pizzas[i].valor;
    }

    return total_vendas;
}

int menu_pizzaria(Pizza *pizzas, int *num_pizzas, int *num_pedidos, Pedido *pedidos, Entregador *entregadores)
{//função (dev) da opção pizzaria no menu
    int opcao;

    do
    {
        printf("\nMenu Pizzaria:\n");
        printf("1. Cadastrar pizzas\n");
        printf("2. Alterar dados da pizza\n");
        printf("3. Remover uma pizza\n");
        printf("4. Despacho da pizza\n");
        printf("5. Exibir entregador\n");
        printf("6. Exibir montante\n");
        printf("7. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Opcao selecionada: Cadastrar pizzas.\n\n");
            cadastrar_pizzas(pizzas, num_pizzas);
            break;
        case 2:
            printf("Opcao selecionada: Alterar dados da pizza.\n\n");
            alterar_dados_pizza(pizzas, num_pizzas);
            break;
        case 3:
            printf("Opcao selecionada: Remover uma pizza.\n\n");
            remover_pizza(pizzas, num_pizzas);
            break;
        case 4:
            printf("Opcao selecionada: Despacho da pizza.\n");
            despacho_pizza(pedidos, num_pedidos, entregadores);
            break;
        case 5:
            printf("Opcao selecionada: Exibir entregador.\n");
            exibir_entregadores(entregadores);
            break;
        case 6:
            printf("Opcao selecionada: Exibir montante.\n");
            float total = somar_vendas(num_pedidos, pizzas);
            printf("Total de vendas: R$ %.2f\n", total);
            break;
        case 7:
            printf("Opcao selecionada: Voltar.\n");
            break;
        default:
            printf("Opcao invalida. Por favor, selecione uma opcao valida.\n");
        }
    } while (opcao != 7);
    return opcao;
}

int menu_cliente(Cliente *clientes, int *num_clientes, Pizza *pizzas, int *num_pizzas, int *num_pedidos, Pedido *pedidos, Entregador *entregadores)
{//função (dev) da opção cliente no menu
    int opcao;

    do
    {
        printf("\nMenu Cliente:\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Alterar dados do cliente\n");
        printf("3. Remover conta\n");
        printf("4. Ver menu com todas as pizzas\n");
        printf("5. Fazer pedido\n");
        printf("6. Recebimento do pedido\n");
        printf("7. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Opcao selecionada: Cadastrar cliente.\n\n");
            cadastrar_cliente(clientes, num_clientes);
            break;
        case 2:
            printf("Opcao selecionada: Alterar dados do cliente.\n\n");
            alterar_dados_cliente(clientes, num_clientes);
            break;
        case 3:
            printf("Opcao selecionada: Remover conta.\n\n");
            remover_conta(clientes, num_clientes);
            break;
        case 4:
            printf("Opcao selecionada: Ver menu com todas as pizzas.\n\n");
            ver_menu_pizzas(pizzas, num_pizzas);
            break;
        case 5:
            printf("Opcao selecionada: Fazer pedido.\n\n");
            fazer_pedido(pedidos, num_pedidos, clientes, num_clientes, pizzas, num_pizzas);
            break;
        case 6:
            printf("Opcao selecionada: Recebimento do pedido.\n\n");
            recebimento_pedido(pedidos, num_pedidos, entregadores);
            break;
        case 7:
            printf("Opcao selecionada: Voltar.\n\n");
            break;
        default:
            printf("Opcao invalida. Por favor, selecione uma opcao valida.\n");
        }
    } while (opcao != 7);
    return opcao;
}

int main()
{
    Pedido pedidos[1000];
    int opcao;
    Pizza pizzas[100];
    int num_pizzas = 0;
    Cliente clientes[1000];
    int num_clientes = 0;
    int num_pedidos = 0;
    Entregador entregadores[10];

    do
    {
        printf("\nBem-vindo! Selecione uma opcao:\n");
        printf("1. Pizzaria\n");
        printf("2. Cliente\n");
        printf("3. Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Opcao selecionada: Pizzaria.\n");
            opcao = menu_pizzaria(pizzas, &num_pizzas, &num_pedidos, pedidos, entregadores);
            break;
        case 2:
            printf("Opcao selecionada: Cliente.\n");
            opcao = menu_cliente(clientes, &num_clientes, pizzas, &num_pizzas, &num_pedidos, pedidos, entregadores);
            break;
        case 3:
            printf("Opcao selecionada: Encerrando...");
            break;
        default:
            printf("Opcao invalida. Por favor, selecione uma opcao valida.\n");
        }

    } while (opcao != 3);

    return 0;
}