
/** \brief suma los dos numeros ingresados
* \param Float primer numero a sumar
* \param Float segundo numero a sumar
* \return Float devuelve el resultado de la suma.
*/

float sumarNumeros(float x, float y)
{
    float total;
    total = x+y;
    return total;
}

/** \brief resta los dos numeros ingresados
* \param Float primer numero a restar
* \param Float segundo numero a restar
* \return Float devuelve el resultado de la resta.
*/

float restarNumeros (float x, float y)
{
    float total;
    total = x-y;
    return total;
}

/** \brief divide los dos numeros ingresados
* \param Float Primer numero a dividir
* \param Float segundo numero a dividir
* \return Float devuelve el resultado de la division.
*/


float dividirNumeros(float x, float y)
{

    float total;
    total = x/y;
    return total;

}

/** \brief multiplica los dos numeros ingresados
* \param float Primer numero a multiplicar
* \param float Segundo numero a multiplicar
* \return float El producto de la multiplicacion.
*/

float multiplicarNumeros(float x, float y)
{
    float total;
    total = x*y;
    return total;

}
/** \brief Calcula el factorial del primer numero ingresado
* \param  int Numero ingresado para obtener calcular el factorial de su parte entera
* \return devuelve el factorial del numero ingresado.
*/

int factorial (int x)
{

    if(x == 0)
        return 1;
    else
        return (x * factorial(x-1));
}



