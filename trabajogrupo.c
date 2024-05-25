#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validarnumeros.h"
#define MAX_PRODUCTS 100
void menu(int xop);
void tablainventarios();

char nombre[MAX_PRODUCTS][50];
int cantidad[MAX_PRODUCTS];
float precio[MAX_PRODUCTS];
int cont = 0;

int main()
{
    int op;
    do
    {
        printf("\e[1;34m-------MENU DE REGISTRO INVENTARIOS PHARMASTOCK-------\e[0m\n");
        printf("Seleccione la opcion a realizar: \n");
        printf("[1] Ingresar Producto Nuevo\n");
        printf("[2] Editar Producto\n");
        printf("[3] Eliminar Producto\n");
        printf("[4] Lista Productos Ingresados\n");
        printf("[5] Terminar\n");
        scanf("%d", &op);
        menu(op);
    } while (op != 5);
    return 0;
}

void menu(int xop)
{
    int i, codigo;
    char cadnombre[50];
    char esnumero[10], esprecio[20];
    int es_valido;
    switch (xop)
    {
    case 1:
        if (cont < MAX_PRODUCTS)
        {
            printf("Ingrese el Nombre del Producto: \n");
            getchar();
            int i = 0;
            while (i < 49)
            {
                char caracter = getchar();
                if (caracter == '\n')
                    break;
                cadnombre[i++] = caracter;
            }
            cadnombre[i] = '\0';
            strcpy(nombre[cont], cadnombre);
            do
            {
                printf("Ingrese la Cantidad del Producto: \n");
                scanf("%s", esnumero);
                es_valido = validarnumero(esnumero);
                if (es_valido == 0)
                {
                    printf("\e[1;31mError: Solo ingrese numeros.\e[0m\n");
                }
            } while (es_valido == 0);
            cantidad[cont] = atoi(esnumero);

            do
            {
                printf("Ingrese el Precio Unitario del Producto: \n");
                scanf("%s", esprecio);
                es_valido = validarnumero(esprecio);
                if (es_valido == 0)
                {
                    printf("\e[1;31mError: Solo ingrese numeros\e[0m\n");
                }
            } while (es_valido == 0);
            precio[cont] = atof(esprecio);

            cont++;
        }
        else
        {
            printf("Inventario lleno. No se puede agregar mas productos.\n");
            printf("\n");
        }
        break;
    case 2:
        if (cont == 0)
        {
            printf("No tiene ningun producto en el inventario todavia.\n");
            printf("\n");
            break;
        }
        else
        {
            do
            {
                printf("----------------TABLA DE CONTENIDO DE INVENTARIOS----------------\n");
                tablainventarios();
                printf("\nPara EDITAR el producto, por favor indique el CODIGO del producto que desea editar. \n");
                scanf("%d", &codigo);
                codigo--;

                if (codigo < 0 || codigo > cont)
                {
                    printf("Código de producto inválido. Por favor ingrese un código válido.\n");
                }
                else
                {
                    printf("Ingrese el nuevo Nombre del Producto: \n");
                    getchar();
                    int j = 0;
                    while (j < 49)
                    {
                        char caracter = getchar();
                        if (caracter == '\n')
                            break;
                        cadnombre[j++] = caracter;
                    }
                    cadnombre[j] = '\0';
                    strcpy(nombre[codigo], cadnombre);
                    do
                    {
                        printf("Ingrese la nueva Cantidad del Producto: \n");
                        scanf("%s", esnumero);
                        es_valido = validarnumero(esnumero);
                        if (es_valido == 0)
                        {
                            printf("\e[1;31mError: Solo ingrese numeros.\e[0m\n");
                        }
                    } while (es_valido == 0);
                    cantidad[codigo] = atoi(esnumero);

                    do
                    {
                        printf("Ingrese el nuevo Precio Unitario del Producto: \n");
                        scanf("%s", esprecio);
                        es_valido = validarnumero(esprecio);
                        if (es_valido == 0)
                        {
                            printf("\e[1;31mError: Solo ingrese numeros\e[0m\n");
                        }
                    } while (es_valido == 0);
                    precio[codigo] = atof(esprecio);
                }
            } while (codigo < 0 || codigo > cont);
        }
        break;
    case 3:
        if (cont == 0)
        {
            printf("No tiene ningun producto en el inventario todavia.\n");
            printf("\n");
            break;
        }
        else
        {
            do
            {
                printf("----------------TABLA DE CONTENIDO DE INVENTARIOS----------------\n");
                tablainventarios();
                printf("\nPara ELIMINAR el producto, por favor indique el CODIGO del producto que desea eliminar. \n");
                scanf("%d", &codigo);
                codigo--;
                if (codigo < 0 || codigo > cont)
                {
                    printf("Código de producto inválido. Por favor ingrese un código válido.\n");
                }
                else
                {
                    for (i = codigo; i < cont; i++)
                    {
                        strcpy(nombre[i], nombre[i + 1]);
                        cantidad[i] = cantidad[i + 1];
                        precio[i] = precio[i + 1];
                    }
                    cont--;
                    printf("\x1B[32mEL PRODUCTO SE HA ELIMINADO CON EXITO\e[0m\n");
                }

            } while (codigo < 0 || codigo > cont);
        }
        break;

    case 4:
        if (cont == 0)
        {
            printf("No tiene ningun producto en el inventario todavia.\n");
            printf("\n");
            break;
        }
        else
        {
            printf("----------------------------------------------------------------------\n");
            printf("\e[1;34m---------------TABLA FINAL INVENTARIOS PHARMASTOCK------------------\e[0m\n");
            printf("----------------------------------------------------------------------\n");
            tablainventarios();
            break;
        }

    case 5:
        printf("\x1B[32mEL PROGRAMA TERMINO CON EXITO\e[0m\n");
        printf("\n");
        break;

    default:
        printf("\e[1;31m Opcion no valida.\e[0m\n");
        printf("\n");
        break;
    }
}

void tablainventarios()
{
    int i;
    printf("CODIGO\t\tPRODUCTO\t\tCANTIDAD\t\tPRECIO\n");
    for (i = 0; i < cont; i++)
    {
        printf("%d\t\t%s\t\t\t%d\t\t\t%.2f\n", i + 1, nombre[i], cantidad[i], precio[i]);
        printf("\n");
    }
}