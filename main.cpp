#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;
#include "content.h"
#include "netflix.h"
#include "disney.h"
#include "prime.h"
#include "pirateria.h"
#include "recomendador.h"
int main()
{

    int menu;
    string consulta;
    NetflixInventario inventarioN;
    DisneyInventario inventarioD;
    PrimeInventario inventarioP;
    recomendador recomendador;
    pirateria piratas;

    cout << "Bienvenido al recomendandador de contenido" << endl;
START:
    cout << "\nPor favor selecciona una opcion" << endl;
    cout << "1. Crea tu contenido" << endl;
    cout << "2. Buscar contenido por titulo " << endl;
    cout << "3. Buscar contenido por anio " << endl;
    cout << "4. Buscar contenido por rating " << endl;
    cout << "5. Salir " << endl;
    cin >> menu;

    switch (menu)
    {

    case 1:
    {
        cout << "Crea tu contenido audiovisual :D" << endl;
        string title, duration, description, type, release_year, rating;

        cout << "Como se llamara tu contenido?: " << endl;
        cin >> title;

        cout << "Tipo de contenido (movie/serie)?: " << endl;
        cin >> type;

        cout << "Cuanto durara (6 seasons) (1:40min) " << endl;
        cin >> duration;

        cout << "Anio de lanzamiento? " << endl;
        cin >> release_year;

        cout << "Una pequena descripcion: " << endl;
        cin >> description;

        cout << "Dale un rating a tu pelicula: (0.0 - 10)" << endl;
        cin >> rating;

        Content c = Content(title, type, duration, release_year, description, rating);
        piratas.agregarPelicula(c);
        recomendador.agregarPeliculaNetflix(c);
        recomendador.agregarPeliculaDisney(c);
        recomendador.agregarPeliculaPrime(c);
        cout << c << endl;
        
    }
        goto START;

    case 2:
    {

        cout << "Que buscas ? " << endl;
        cin >> consulta;
        
        cout << "Contenido que puedes encontrar en Netflix: " << endl;
        vector<Content> productos = recomendador.getProductosTitleNetflix(consulta);
        for (int i = 0; i < productos.size(); i++)
        {
            cout << productos[i] << endl;
        }

        cout << "\nContenido que puedes encontrar en Disney: " << endl;
        vector<Content> productosD = recomendador.getProductosTitleDisney(consulta);
        for (int i = 0; i < productosD.size(); i++)
        {
            cout << productosD[i] << endl;
        }

        cout << "\nContenido que puedes encontrar en Prime: " << endl;
        vector<Content> productosP = recomendador.getProductosTitlePrime(consulta);
        for (int i = 0; i < productosP.size(); i++)
        {
            cout << productosP[i] << endl;
        }
    }
        goto START;

    case 3:
    {
        cout << "Que buscas ? " << endl;
        cin >> consulta;

        cout << "Contenido que puedes encontrar en Netflix: " << endl;
        vector<Content> productos = recomendador.getProductosRatingNetflix(consulta);
        for (int i = 0; i < productos.size(); i++)
        {
            cout << productos[i] << endl;
        }

        cout << "\nContenido que puedes encontrar en Disney: " << endl;
        vector<Content> productosD = recomendador.getProductosRatingDisney(consulta);
        for (int i = 0; i < productosD.size(); i++)
        {
            cout << productosD[i] << endl;
        }

        cout << "\nContenido que puedes encontrar en Prime: " << endl;
        vector<Content> productosP = recomendador.getProductosRatingPrime(consulta);
        for (int i = 0; i < productosP.size(); i++)
        {
            cout << productosP[i] << endl;
        }
    }
        goto START;

    case 4:
    {
        cout << "Que buscas ? " << endl;
        cin >> consulta;

        cout << "Contenido que puedes encontrar en Netflix: " << endl;
        vector<Content> productos = recomendador.getProductosYearNetflix(consulta);
        for (int i = 0; i < productos.size(); i++)
        {
            cout << productos[i] << endl;
        }

        cout << "\nContenido que puedes encontrar en Disney: " << endl;
        vector<Content> productosD = recomendador.getProductosYearDisney(consulta);
        for (int i = 0; i < productosD.size(); i++)
        {
            cout << productosD[i] << endl;
        }

        cout << "\nContenido que puedes encontrar en Prime: " << endl;
        vector<Content> productosP = recomendador.getProductosYearPrime(consulta);
        for (int i = 0; i < productosP.size(); i++)
        {
            cout << productosP[i] << endl;
        }
    }
        goto START;

    case 5:
    {
        return 0;
    }
    break;

    default:
        cout << "Introduce una opción válida" << endl;
        goto START;
    }
}
