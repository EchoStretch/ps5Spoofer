#include <stdio.h>
#include <string.h>
#include <ps5/kernel.h>

typedef struct notify_request {
  char useless1[45];
  char message[3075];
} notify_request_t;


int sceKernelSendNotificationRequest(int, notify_request_t*, size_t, int);
unsigned int OFFSET_KERNEL_PS4SDK_55 = 0x023D9048;
unsigned int OFFSET_KERNEL_PS4SDK_51_50_502 = 0x023D8F38;
unsigned int OFFSET_KERNEL_PS4SDK_43 = 0x16ABE88;

int
main() {
  notify_request_t req;

  bzero(&req, sizeof req);
  switch(kernel_get_fw_version() & 0xffff0000) {
      case 0x4030000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_43, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
      
      case 0x5000000:
      case 0x5020000:
      case 0x5100000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_51_50_502, 0x99999999);
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
      case 0x5500000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_55, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
  }
  strncpy(req.message, "Your firmware version is not supported", sizeof req.message);
  return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
}

