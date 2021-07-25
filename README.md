# Proyecto

	Proyecto - Administración, compra y venta de productos de negocios.

### Estructura General

El repositorio cuenta con X carpetas, un readme.md y un archivo documentacion.pdf para una información más detallada sobre la solución y el código escrito. Cada una de las carpetas resuelve una etapa de ésta, en general se tienen los siguientes archivos.

- Comuna.cpp
- Comuna.h
- Pedestrian.cpp
- Pedestrian.h
- Simulator.cpp
- Simulator.h
- mainwindow.cpp
- mainwindow.h
- mainwindow.ui
- settings.cpp
- settings.h
- settings.ui
- Extra.cpp
- Extra.pro
- config.txt

El archivo principal de ejecución (main) es Extra.cpp. Además, el archivo Config.txt contiene los parámetros de la simulación de la forma:

		<N. de Individuos> <N. de Infectados> <Tiempo que dura la infección [s]> 
		<Ancho de la comuna [m]> <Alto de la comuna [m]>
		<Velocidad de los individuos [m/s]> <∆t [s]> <∆θ [rad]>
		<Distancia de contagio [m]> <Razón de uso de mascarilla> <p0> <p1> <p2> //Probabilidades de Contagio
		<Cant. de Vacunatorios> <Tamaño de los Vacunatorios> <Tiempo para empezar a Vacunar [s]>

**NOTA:** Para las etapas anteriores el archivo main se encuentra como stageX.cpp, donde X varía según la etapa en la que se desee ejecutar. Notar también que en etapas anteriores se prescinde de algunos de los archivos, según lo solicitado.

### Ejecución

Antes de ejecutar deberemos realizar un seteo previo, a continuación los pasos. 

- Se debe descargar la carpeta de la etapa (Stage) que se desee simular.
- Se debe iniciar Qt Creator, cargando el proyecto basado en el archivo con extensión **.pro** descargado en el paso anterior.
- Asegurarse de tener descargado e instalado el módulo Qt Charts. 
- Se debe agregar a la carpeta build generada por QtCreator para la etapa el archivo config.txt
- Se debe agregar en la parte de ejecución del QtCreator el argumento de linea de comando config.txt

Finalmente, para ejecutar cada etapa del programa (con el seteo descrito anteriormente) simplemente dentro del IDE dar al botón Run, simbolizado con una flecha verde.

Dentro del simulador se encuentran las opciones de Control y Settings, la primera nos permite ejecutar los comandos Start y Stop para poder ejecutar y parar la simulación. Por otro lado, la ventana de Settings nos permite colocar los parámetros de la simulación a gusto dentro de los márgenes impuestos. Por ultimo, con la simulación ya en ejecución, se puede acelerar la simulación presionando la tecla &#8594; y para ralentizar la simulación la tecla &#8592;.

---
### Otros
  Se opta por la etapa extra.

  Se toma como referencia la Tarea 2 para poder trabajar modularmente, teniendo una referencia en otro lenguaje de programación y ajustando solamente lo necesario. El repositorio se encuentra [aquí](https://gitlab.com/gt12-elo329/andrade.miguel-cruces.manuel-pizarro.kevin-troncoso.pablo-tarea2.2021.1).
