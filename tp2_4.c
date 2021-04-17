#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int velocidad;
    int year;
    int cantidad;
    char *tipo_cpu;
} compu;

compu retornarPC(compu pc, char *tipos);
void cargarCompus(compu *caracteristicas, char *tipos, int num_pc);
void mostrarCompus(compu *caracteristicas, int num_pc);
void masVieja(compu *caracteristicas, int num_pc);
void mayorVelocidad(compu *caracteristicas, int num_pc);

int main () {
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    char *p_tipos = &tipos[0][0];
    int num_pc;
    compu *caracteristicas, pc;

    pc = retornarPC(pc, p_tipos);
    puts("Caracteristicas de la PC:");
    printf("Velocidad: %d GHz\n", pc.velocidad);
    printf("Anio: %d\n", pc.year);
    printf("Nucleos: %d\n", pc.cantidad);
    printf("Tipo de procesador: ");
    puts(pc.tipo_cpu);

    puts("Ingrese la cantidad de PCs a cargar: ");
    scanf("%d", &num_pc);
    caracteristicas = (compu*) malloc(sizeof(compu) * num_pc);

    cargarCompus(caracteristicas, p_tipos, num_pc);
    mostrarCompus(caracteristicas, num_pc);
    masVieja(caracteristicas, num_pc);
    mayorVelocidad(caracteristicas, num_pc);

    free(caracteristicas);
    
    getchar();

    return 0;
}

//Función que recibe una estructura vacía como argumento y carga sus características
compu retornarPC(compu pc, char *tipos) {
    int aux;

    pc.velocidad = 1 + rand() % 3;
    pc.year = 2000 + rand() % 18;
    pc.cantidad = 1 + rand() % 4;
    aux = rand() % 6;
    pc.tipo_cpu = tipos+aux*10;

    return pc;
}

/*Función que recibe el puntero al arreglo de estructuras y carga el mismo
con las características de cada PC*/
void cargarCompus(compu *caracteristicas, char *tipos, int num_pc) {

    for (int i = 0; i < num_pc; i++)
    {
        int aux;

        caracteristicas[i].velocidad = 1 + rand() % 3;
        caracteristicas[i].year = 2000 + rand() % 18;
        caracteristicas[i].cantidad = 1 + rand() % 4;
        aux = rand() % 6;
        caracteristicas[i].tipo_cpu = tipos+aux*10;
    }//for end
}

//Función para mostrar la lista de PCs
void mostrarCompus(compu *caracteristicas, int num_pc) {

    for (int i = 0; i < num_pc; i++)
    {
        printf("\nPC %d - Caracteristicas:", i+1);
        printf("\nVelocidad: %d GHz\n", caracteristicas[i].velocidad);
        printf("Anio: %d\n", caracteristicas[i].year);
        printf("Nucleos: %d\n", caracteristicas[i].cantidad);
        printf("Tipo de procesador: ");
        puts(caracteristicas[i].tipo_cpu);
    }//for end
}

//Fución para presentar la PC más vieja
void masVieja(compu *caracteristicas, int num_pc) {
    int aux = 2017;

    for (int i = 0; i < num_pc; i++)
    {
        if (caracteristicas[i].year < aux)
        {
            aux = caracteristicas[i].year;
        }// if end
        
    }//for end

    printf("\nPCs mas viejas: \n");

    for (int i = 0; i < num_pc; i++)
    {
        if (caracteristicas[i].year == aux)
        {
            printf("\nVelocidad: %d GHz\n", caracteristicas[i].velocidad);
            printf("Anio: %d\n", caracteristicas[i].year);
            printf("Nucleos: %d\n", caracteristicas[i].cantidad);
            printf("Tipo de procesador: ");
            puts(caracteristicas[i].tipo_cpu);
        }// if end
        
    }//for end    

}

//Función para presentar la PC de mayor velocidad
void mayorVelocidad(compu *caracteristicas, int num_pc) {
    int aux = 1;

    for (int i = 0; i < num_pc; i++)
    {
        if (caracteristicas[i].velocidad > aux)
        {
            aux = caracteristicas[i].velocidad;
        }// if end
        
    }//for end

    printf("\nPCs mas rapidas: \n");

    for (int i = 0; i < num_pc; i++)
    {
        if (caracteristicas[i].velocidad == aux)
        {
            printf("\nVelocidad: %d GHz\n", caracteristicas[i].velocidad);
            printf("Anio: %d\n", caracteristicas[i].year);
            printf("Nucleos: %d\n", caracteristicas[i].cantidad);
            printf("Tipo de procesador: ");
            puts(caracteristicas[i].tipo_cpu);
        }// if end
        
    }//for end
}