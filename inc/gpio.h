#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

/** @file gpio.h
 ** @brief Definiciones de el driver de gpio.
 **/

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */
typedef struct gpio_s * gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

gpio_t gpio_create(uint8_t puerto,  uint8_t pin);
void gpio_set_direction(gpio_t gpio, bool output);
void gpio_set_output(gpio_t gpio, bool output);
void gpio_set_state(gpio_t gpio, bool state);
bool gpio_get_state(gpio_t gpio);

/**
 * @brief Función principal del sistema, se ejecuta al iniciar el programa
 *
 * @return int Valor de retorno, cero si esta todo bien, negativo si hay un error
 */
int main(void);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif