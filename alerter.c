#include <stdio.h>
#include <assert.h>

#define MAX_THRESHOLD 200
#define ok 200
#define not_ok 500

int alertFailureCount = 0;

int stub_networkAlert(float celcius)
{
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius <= MAX_THRESHOLD)
    {
        return 200;
    }
    else
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
    }
}

/**
 * This stub will convert temperature units from farenheit to celcius
 * @param[in]  - temperature in farenheit
 * @param[out] - temperature in celcius
 */
float stub_convertFtoC( float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit) 
{
    float celcius       = stub_convertFtoC(farenheit);
    int   returnCode    = stub_networkAlert(celcius);
    
    if (returnCode == not_ok)
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }

    assert((returnCode == ok) && (celcius <= MAX_THRESHOLD));
    assert((returnCode == not_ok) && (celcius > MAX_THRESHOLD));
    
}

int main() 
{
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(300.8);
    alertInCelcius(401.9);
    
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well \n");
    return 0;
}
