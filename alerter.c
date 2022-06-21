#include <stdio.h>
#include <assert.h>
#include "defines.h"
#ifdef unit_test_enable
#include "test_alerter.h"
#else
#include "alerter.h"
#endif

int alertFailureCount = 0;

void alertInCelcius(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
#ifdef unit_test_enable
    int returnCode = networkAlertStub(celcius);
#else
    int returnCode = networkAlert(celcius);
#endif
    if (returnCode != 200)
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
