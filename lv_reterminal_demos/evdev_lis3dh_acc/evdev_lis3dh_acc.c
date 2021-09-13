/**
 * @file evdev_lis3dh_acc.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "evdev_lis3dh_acc.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#if USE_BSD_EVDEV
#include <dev/evdev/input.h>
#else
#include <linux/input.h>
#endif

/*********************
 *      DEFINES
 *********************/
#define ACC_EVDEV_NAME "/dev/input/event3"

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
int evdev_fd;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize the evdev interface
 */
void evdev_lis3dh_init(void)
{
#if USE_BSD_EVDEV
    evdev_fd = open(ACC_EVDEV_NAME, O_RDWR | O_NOCTTY);
#else
    evdev_fd = open(ACC_EVDEV_NAME, O_RDWR | O_NOCTTY | O_NDELAY);
#endif
    if(evdev_fd == -1) {
        perror("unable open evdev interface:");
        return;
    }

#if USE_BSD_EVDEV
    fcntl(evdev_fd, F_SETFL, O_NONBLOCK);
#else
    fcntl(evdev_fd, F_SETFL, O_ASYNC | O_NONBLOCK);
#endif

}
/**
 * reconfigure the device file for evdev
 * @param dev_name set the evdev device filename
 * @return true: the device file set complete
 *         false: the device file doesn't exist current system
 */
bool evdev_lis3dh_set_file(char* dev_name)
{ 
     if(evdev_fd != -1) {
        close(evdev_fd);
     }
#if USE_BSD_EVDEV
     evdev_fd = open(dev_name, O_RDWR | O_NOCTTY);
#else
     evdev_fd = open(dev_name, O_RDWR | O_NOCTTY | O_NDELAY);
#endif

     if(evdev_fd == -1) {
        perror("unable open evdev interface:");
        return false;
     }

#if USE_BSD_EVDEV
     fcntl(evdev_fd, F_SETFL, O_NONBLOCK);
#else
     fcntl(evdev_fd, F_SETFL, O_ASYNC | O_NONBLOCK);
#endif

     return true;
}
/**
 * Get the current readings from accelerometer
 * @param data store the evdev data here
 * @return false: because the points are not buffered, so no more data to be read
 */
bool evdev_lis3dh_read(struct acc_data *data)
{
    struct input_event in;

    while(read(evdev_fd, &in, sizeof(struct input_event)) > 0) {
      if(in.type == EV_ABS) {
          if (in.code == ABS_X) { data->x_val = in.value; }
          else if (in.code == ABS_Y) { data->y_val = in.value; }
          else if (in.code == ABS_Z) { data->z_val = in.value;  }
      }
    }

    return false;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


