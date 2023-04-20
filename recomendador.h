#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;
class recomendador
{
private:
    vector<Content> peliculasDisney; // Se cra un vector de la clase Content
    vector<Content> peliculasNetflix;
    vector<Content> peliculasPrime;

    void cargaDatosDisney() // Lectura de los Datos
    {
        ifstream archivoDisney("Disney_plus_shows.csv"); // Lectura del CSV
        string id, title, plot, type, rated, release_year, released_at, added_at, duration, genre, director, writer, actors, language, contry, awards, metascore, imdb_rating, imdb_votes;
        string linea;

        getline(archivoDisney, linea);
        //cout << linea;

        while (getline(archivoDisney, linea)) // se le cada header del CSV
        {
            //cout << linea << endl;// parsing
            istringstream parser(linea);
            getline(parser, id, ',');
            getline(parser, title, ',');
            getline(parser, plot, ',');
            getline(parser, type, ',');
            getline(parser, rated, ',');
            getline(parser, release_year, ',');
            getline(parser, released_at, ',');
            getline(parser, added_at, ',');
            getline(parser, duration, ',');
            getline(parser, genre, ',');
            getline(parser, director, ',');
            getline(parser, writer, ',');
            getline(parser, actors, ',');
            getline(parser, language, ',');
            getline(parser, contry, ',');
            getline(parser, awards, ',');
            getline(parser, metascore, ',');
            getline(parser, imdb_rating, ',');
            getline(parser, imdb_votes, ',');

            Content ptem = Content(title, type, duration, release_year, plot, imdb_rating);
            peliculasDisney.push_back(ptem);
        }
    }
    
    void cargaDatosNetflix()
    {
        ifstream archivo("Netflix_TV_Shows.csv");
        string id, type, title, director, cast, country, date_added, rating, duration, listed_in, description, release_year;
        

        string linea;

        getline(archivo, linea);
        //cout << linea;

        while (getline(archivo, linea))
        {
            //cout << linea << endl;// parsing
            istringstream parser(linea);
            getline(parser, id, ',');
            getline(parser, type, ',');
            getline(parser, title, ',');
            getline(parser, director, ',');
            getline(parser, cast, ',');
            getline(parser, country, ',');
            getline(parser, date_added, ',');
            getline(parser, release_year, ',');
            getline(parser, rating, ',');
            getline(parser, duration, ',');
            getline(parser, listed_in, ',');
            getline(parser, description, ',');

            Content ptem = Content(title,type,duration, release_year,description,rating);
            peliculasNetflix.push_back(ptem);
        }
    }
    
    void cargaDatosPrime()
    {
        ifstream archivo("Prime_TV_Shows.csv");
        string num, title, release_year, duration, language, genre, imdb_rating, age_viewers;
        
        string linea;

        getline(archivo, linea);
        //cout << linea;

        while (getline(archivo, linea))
        {
            //cout << linea << endl;// parsing
            istringstream parser(linea);
            getline(parser, num, ',');
            getline(parser, title, ',');
            getline(parser, release_year, ',');
            getline(parser, duration, ',');
            getline(parser, language, ',');
            getline(parser, genre, ',');
            getline(parser, imdb_rating, ',');
            getline(parser, age_viewers, ',');

            Content ptem = Content(title,language,duration, release_year,genre,imdb_rating);
            peliculasPrime.push_back(ptem);
            peliculasPrime.push_back(ptem);
        }
    }

public:
    recomendador() // Vector de content con los datos del CSV
    {
        peliculasDisney = vector<Content>();
        cargaDatosDisney();
        peliculasNetflix = vector<Content>();
        cargaDatosNetflix();
        peliculasPrime = vector<Content>();
        cargaDatosPrime();
    }

    void agregarPeliculaDisney(Content contenido) // Agregar un contenido nuevo
    {
        peliculasDisney.push_back(contenido);
    }

    void agregarPeliculaNetflix(Content contenido)
    {
        peliculasNetflix.push_back(contenido);
    }

    void agregarPeliculaPrime(Content contenido)
    {
        peliculasPrime.push_back(contenido);
    }

    vector<Content> getProductosTitleDisney(string consulta)
    {
        vector<Content> salida = vector<Content>();

        for (int i = 0; i < peliculasDisney.size(); i++)
        {
            if (peliculasDisney[i].getTitle().find(consulta) != string::npos)
            {
                salida.push_back(peliculasDisney[i]);
            }
        }

        return salida;
    }

    vector<Content> getProductosYearDisney(string consulta)
    {
        vector<Content> salida = vector<Content>();

        for (int i = 0; i < peliculasDisney.size(); i++)
        {
            if (peliculasDisney[i].getYear().find(consulta) != string::npos)
            {
                salida.push_back(peliculasDisney[i]);
            }
        }

        return salida;
    }

    vector<Content> getProductosRatingDisney(string consulta)
    {
        vector<Content> salida = vector<Content>();

        for (int i = 0; i < peliculasDisney.size(); i++)
        {
            if (peliculasDisney[i].getRating().find(consulta) != string::npos)
            {
                salida.push_back(peliculasDisney[i]);
            }
        }

        return salida;
    }

    vector<Content> getProductosTitleNetflix(string consulta)
    {
        vector<Content> salida = vector<Content>();

        for (int i = 0; i < peliculasNetflix.size(); i++)
        {
            if (peliculasNetflix[i].getTitle().find(consulta) != string::npos)
            {
                salida.push_back(peliculasNetflix[i]);
            }
        }

        return salida;
    }

    vector<Content> getProductosRatingNetflix(string consulta)
    {
        vector<Content> salida = vector<Content>();

        for (int i = 0; i < peliculasNetflix.size(); i++)
        {
            if (peliculasNetflix[i].getRating().find(consulta) != string::npos)
            {
                salida.push_back(peliculasNetflix[i]);
            }
        }

        return salida;
    }

    vector<Content> getProductosYearNetflix(string consulta)
    {
        vector<Content> salida = vector<Content>();

        for (int i = 0; i < peliculasNetflix.size(); i++)
        {
            if (peliculasNetflix[i].getYear().find(consulta) != string::npos)
            {
                salida.push_back(peliculasNetflix[i]);
            }
        }

        return salida;
    }

    vector<Content> getProductosTitlePrime(string consulta)
    {
        vector<Content> salida = vector<Content>();

        for (int i = 0; i < peliculasPrime.size(); i++)
        {
            if (peliculasPrime[i].getTitle().find(consulta) != string::npos)
            {
                salida.push_back(peliculasPrime[i]);
            }
        }

        return salida;
    }

    vector<Content> getProductosYearPrime(string consulta)
    {
        vector<Content> salida = vector<Content>();

        for (int i = 0; i < peliculasPrime.size(); i++)
        {
            if (peliculasPrime[i].getYear().find(consulta) != string::npos)
            {
                salida.push_back(peliculasPrime[i]);
            }
        }

        return salida;
    }

    vector<Content> getProductosRatingPrime(string consulta)
    {
        vector<Content> salida = vector<Content>();

        for (int i = 0; i < peliculasPrime.size(); i++)
        {
            if (peliculasPrime[i].getRating().find(consulta) != string::npos)
            {
                salida.push_back(peliculasPrime[i]);
            }
        }

        return salida;
    }


    friend ostream &operator<<(ostream &salida, const recomendador &inventario); // Operador friend para la salida de datos
};

ostream &operator<<(ostream &salida, const recomendador &inventario) // operador de los datos de 
{
    if (inventario.peliculasNetflix.size() == 0)
    {
        salida << "Empty";
    }
    for (int i = 0; i < inventario.peliculasDisney.size(); i++)
    {
        salida << inventario.peliculasDisney[i] << endl;
    }
    return salida;
}