#include <stdio.h>
#include <string.h>

int main(){
    // Variables
    char nomProducto[10][30];
    char productoBuscado[30];
    float precioProducto[10], totalInventario = 0;
    float maxPrecio, minPrecio;
    int indiceMasCaro = 0;
    int indiceMasBarato = 0;
    int opc1, opc2, opc3, productosIngresados = 0;
// Menu de opciones
    do{
        printf("Menu de opciones\n");
        printf("1. Ingresar Productos\n");
        printf("2. Ver precio total de inventario\n");
        printf("3. Ver producto mas caro y el mas barato\n");
        printf("4. Ver promedio de precio\n");
        printf("5. Buscar producto\n");
        printf("6. Salir\n");
        scanf("%d", &opc1);
// Switch para las opciones del menu
// Ingreso de productos
        switch(opc1){
            case 1:
                printf("Usted ha seleccionado la opcion 1: Ingresar Productos\n");     
                    for(int i = 0; i < 10; i++){
                    printf("Ingrese el nombre del producto %d:\n", i + 1);
                    scanf("%29s", nomProducto[i]);
                    printf("Ingrese el precio del producto %s:\n", nomProducto[i]);
                    scanf("%f", &precioProducto[i]);
                    totalInventario += precioProducto[i];
                    productosIngresados++;
                printf("Desea ingresar otro producto? (1. Si / 2. No)\n");
                scanf("%d", &opc3);
                if(opc3 == 2){
                    break;  
                }
            }
                break;
// Ver precio total de inventario
            case 2:
                printf("Usted ha seleccionado la opcion 2: Ver precio total de inventario\n");
                printf("El precio total del inventario es: %.2f$\n", totalInventario);
                break;
// Ver producto mas caro y el mas barato
            case 3: {
                printf("Usted ha seleccionado la opcion 3: Ver producto mas caro y el mas barato\n");
                if(productosIngresados == 0){
                    printf("Primero debe ingresar los productos.\n");
                    break;
                }
                minPrecio = precioProducto[0];
                maxPrecio = precioProducto[0];

                for(int i = 1; i < productosIngresados; i++){
                    if(precioProducto[i] > maxPrecio){
                        maxPrecio = precioProducto[i];
                        indiceMasCaro = i;
                    }
                    if(precioProducto[i] < minPrecio){
                        minPrecio = precioProducto[i];
                        indiceMasBarato = i;
                    }
                }
                printf("El producto mas caro es %s, con un precio de %.2f$\n",
                       nomProducto[indiceMasCaro], maxPrecio);
                printf("El producto mas barato es %s, con un precio de %.2f$\n",
                       nomProducto[indiceMasBarato], minPrecio);
                break;
            }
// Ver promedio del precio de los productos
            case 4:
                printf("Usted ha seleccionado la opcion 4: Ver promedio de precio\n");
                if(productosIngresados == 0){
                    printf("Primero debe ingresar los productos.\n");
                } else {
                    float promedio = totalInventario / productosIngresados;
                    printf("El promedio de precio es: %.2f$\n", promedio);
                }
                break;
// Buscar producto
            case 5: {
                printf("Usted ha seleccionado la opcion 5: Buscar producto\n");
                if(productosIngresados == 0){
                    printf("Primero debe ingresar los productos.\n");
                    break;
                }

                printf("Ingrese el nombre del producto que desea buscar:\n");
                scanf("%29s", productoBuscado);
                int encontrado = 0;
                for(int i = 0; i < productosIngresados; i++){
                    if(strcmp(nomProducto[i], productoBuscado) == 0){
                        printf("Producto: %s | Precio: %.2f$\n", nomProducto[i], precioProducto[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado){
                    printf("No se encontro el producto %s.\n", productoBuscado);
                }
                break;
            }
// Salir
            case 6:{
              printf("Usted ha seleccionado la opcion 6: Salir\n");
            return 0;
             break;           
            }  

            default:
                printf("Opcion no valida.\n");
                break;
        }
     printf("Desea seleccionar otra opcion? (1. Si / 2. No)\n");
    scanf("%d", &opc2);       
    }while(opc2 == 1);

    return 0;
}
