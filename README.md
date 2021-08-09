# Proyecto

	Proyecto - Administración, compra y venta de productos de negocios.

### Estructura General

El repositorio cuenta con 3 carpetas (2 de ellas en el primer nivel), un README.md y un archivo informe.html para una información más detallada sobre la solución y el código escrito. En este respositorio se tiene la siguiente estructura:

    - ResourcesHTML
      - Imágenes que son usadas en informe.html
    - Project
      - Resources
        - Imágenes para el proyecto
      - Archivos para clase Caja: caja.cpp, caja.h y caja.ui
      - Archivos para clase compras: compras.cpp, compras.h y compras.ui
      - Archivos para clase inventario inventario.cpp, inventario.h y inventario.ui
      - Archivos para clase mainwindow mainwindow.cpp, mainwindow.h y mainwindow.ui
      - Archivos para clase producto producto.cpp, producto.h y producto.ui
      - Archivos para clase ventas ventas.cpp, ventas.h y ventas.ui
      - main.cpp
      - Proyecto.pro
    - informe.html
    - README.md

El archivo principal de ejecución (main) es main.cpp. Además las imágenes se encuentran ordenadas según si son usadas para el proyecto en sí o para el archivo HTML.


### Ejecución

Antes de ejecutar deberemos realizar un seteo previo, a continuación los pasos. 

- Se debe descargar el archivo comprimido del proyecto.
- Se debe iniciar Qt Creator, cargando el proyecto basado en el archivo con extensión **.pro** descargado en el paso anterior.

Finalmente, para ejecutar cada etapa del programa (con el seteo descrito anteriormente) simplemente dentro del IDE dar al botón Run, simbolizado con una flecha verde.

Dentro de la GUI se encuentran las opciones de Ventas, Compras e Inventario. La primera nos permite ejecutar los comandos Venta y Caja para poder realizar ventas a los clientes y chequear el estado de la caja durante el día (o días pasados). En segundo lugar, la opción de Compras nos permite ingresar una compra realizada al proveedor de preferencia. Finalmente la sección de Inventario nos permite acceder al inventario mismo y modificarlo si es necesario, en conjunto con la opción de Producto para añadir un nuevo o eliminarlo de la base de datos.
