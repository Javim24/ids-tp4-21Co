#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

/** @file gpio.h
 ** @brief Definiciones de el driver de gpio.
 ** @author  Javier Mosconi
 ** @date 2024-06-10
 **/

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */
/**
** @brief Puntero a estructura anónima para referenciar el objeto gpio.
**/
typedef struct gpio_s * gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Función que construye un objeto gpio  en base a los parámetros envíados, y devuelve un
 * puntero a la instancia del objeto.
 * @return gpio_t puntero a la instancia del objeto creado. Si no lo pudo crear devuelve NULL.
 */
gpio_t gpio_create(uint8_t puerto, uint8_t pin);

/**
 * @brief Configura la dirección del objeto gpio. Puede ser salida o entrada.
 */
void gpio_set_direction(gpio_t gpio, bool output);

/**
 * @brief Establece el estado de un gpio configurado como salida.
 */
void gpio_set_state(gpio_t gpio, bool state);

/**
 * @brief Lee el estado de un gpio.
 * @return bool: Estado del gpio.
 */
bool gpio_get_state(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif