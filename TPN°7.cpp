#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int SonLatasEnLaHilera(string f);
vector<int> EsCantidadLatasSecuencia(string f, vector<int> c);
int SonLatasDeSecuenciaLarga(string f, vector<int> c);
int SonLatasDeSecuenciaCorta(string f, vector<int> c);
int EsDistanciaEntreSecuencias (int cant, int n1, int n2);

int main()
{
    string etiquetas;
    vector<int> c;
    int cantlatas, m1, m2;
    cout << "Ingresa las etiquetas: ";
    getline(cin, etiquetas);
    cantlatas = SonLatasEnLaHilera(etiquetas);
    c = EsCantidadLatasSecuencia(etiquetas, c);
    m1 = SonLatasDeSecuenciaLarga(etiquetas, c);
    m2 = SonLatasDeSecuenciaCorta(etiquetas, c);
    cout << "La cantidad de latas en la hilera es: " << cantlatas << endl;
    cout << "La cantidad de latas bien etiquetadas en la secuencia larga es: " << m1 << endl;
    cout << "La cantidad de latas bien etiquetadas en la secuencia corta es: " << m2 << endl;
    cout << "La distancia entre las secuencias más largas es: " << EsDistanciaEntreSecuencias(cantlatas, m1, m2) << endl;
    return 0;
}
int SonLatasEnLaHilera(string f)
{
	int l = 0;
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i] != 'F')
		{
			l++;	
		}	
	}
	return l;
}
vector<int> EsCantidadLatasSecuencia(string f, vector<int> c)
{
    int e = 1;
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i - 1] == 'G' && f[i] == 'G')
        {
            e++;
        }
        if (f[i] != 'G' && e > 1)
        {
            c.push_back(e);
            e = 1;
        }
    }
    c.push_back(e);
    sort(c.begin(), c.end(), greater<int>());
    return c;
}
int SonLatasDeSecuenciaLarga(string f, vector<int> c)
{
    if (c.empty())
    {
        return 0;
    }
    return c.front();
}
int SonLatasDeSecuenciaCorta(string f, vector<int> c)
{
    if (c.size() < 2)
    {
        return 0;
    }
    return c[1];
}
int EsDistanciaEntreSecuencias (int cant, int n1, int n2)
{
    int dis = 0;
    dis = cant - (n1 + n2);
    return dis;
}