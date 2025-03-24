#include <stdio.h>
#include <string.h>

// Define a structure to store card information
typedef struct {
    char estado;
    char codigo[4];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Function to pre-fill card data based on city selection
void preencherCarta(Carta *carta, int opcao) {
    switch (opcao) {
        case 1: // São Paulo
            carta->estado = 'A';
            strcpy(carta->codigo, "A01");
            strcpy(carta->cidade, "São Paulo");
            carta->populacao = 12325000;
            carta->area = 1521.11;
            carta->pib = 699.28;
            carta->pontosTuristicos = 50;
            break;
        case 2: // Rio de Janeiro
            carta->estado = 'B';
            strcpy(carta->codigo, "B02");
            strcpy(carta->cidade, "Rio de Janeiro");
            carta->populacao = 6748000;
            carta->area = 1200.25;
            carta->pib = 300.50;
            carta->pontosTuristicos = 30;
            break;
        default:
            // Manual input will be handled in the main function
            break;
    }
}

int main() {
    Carta cartas[2];
    int opcao;
    
    // Input data for two cards
    for (int i = 0; i < 2; i++) {
        printf("\n=== Carta %d ===\n", i + 1);
        printf("Escolha uma opção:\n");
        printf("1. São Paulo\n");
        printf("2. Rio de Janeiro\n");
        printf("3. Inserir dados manualmente\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        if (opcao == 1 || opcao == 2) {
            preencherCarta(&cartas[i], opcao);
        } else {
            printf("\nInsira os dados para a Carta %d:\n", i + 1);
            
            printf("Estado (A-H): ");
            scanf(" %c", &cartas[i].estado);
            
            printf("Código da Carta (ex: A01): ");
            scanf("%s", cartas[i].codigo);
            
            // Clear input buffer before reading string
            while (getchar() != '\n');
            
            printf("Nome da Cidade: ");
            fgets(cartas[i].cidade, 50, stdin);
            // Remove newline character if present
            size_t len = strlen(cartas[i].cidade);
            if (len > 0 && cartas[i].cidade[len-1] == '\n')
                cartas[i].cidade[len-1] = '\0';
            
            printf("População: ");
            scanf("%d", &cartas[i].populacao);
            
            printf("Área (km²): ");
            scanf("%f", &cartas[i].area);
            
            printf("PIB (bilhões de reais): ");
            scanf("%f", &cartas[i].pib);
            
            printf("Número de Pontos Turísticos: ");
            scanf("%d", &cartas[i].pontosTuristicos);
            
            // Clear input buffer
            while (getchar() != '\n' && getchar() != EOF);
        }
    }
    
    // Display card information
    printf("\n=== INFORMAÇÕES DAS CARTAS ===\n");
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].cidade);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
    }
    
    return 0;
}
