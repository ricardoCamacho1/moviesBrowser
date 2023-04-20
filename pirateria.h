
class pirateria
{
private:
    string title, duration, description, type, release_year, rating;
    vector<Content> peliculas;
public:
    pirateria(string title = " Title", string type = "Movie", string duration = "0 season", string release_year = "2020", string description = "No description", string rating = "0") // Argumentos escensiales para cada contenido audo visual
    {
        this->title = title;
        this->duration = duration;
        this->release_year = release_year;
        this->description = description;
        this->type = type;
        this->rating = rating;
    }

    pirateria(const Content &contenido) // Metodo para agregar contenido ya hecho
    {
        this->title = contenido.getTitle();
        this->duration = contenido.getDescription();
        this->release_year = contenido.getYear();
        this->description = contenido.getDescription();
        this->type = contenido.getType();
        this->rating = contenido.getRating();
    }
    
    void agregarPelicula(Content contenido) // Agregar un contenido nuevo
    {
        peliculas.push_back(contenido);
    }

    pirateria operator+(const pirateria & suma)
    {
        stringstream ss; 
        int irating;
        ss << rating;  
        ss >> irating;

        int irating2;
        ss << suma.rating;  
        ss >> irating2;
        irating = irating + irating2;

        string srating;
        ss << irating;  
        ss >> srating;
        return pirateria(suma.title,suma.type,suma.duration,suma.release_year,suma.description, srating);
    }


friend ostream &operator<<(ostream &salida, const pirateria & contenido); // Funcion friend para modificador de operador
};


ostream &operator<<(ostream &salida, const pirateria &contenido)
{
    for (int i = 0; i < contenido.peliculas.size(); i++)
    {
        salida << contenido.peliculas[i] << endl;
    }
    return salida;
} // Modificador de operador, para la salida de los datos del contenido creado.


