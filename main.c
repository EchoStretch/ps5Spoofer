#include <stdio.h>
#include <string.h>
#include <ps5/kernel.h>

typedef struct notify_request {
  char useless1[45];
  char message[3075];
} notify_request_t;


int sceKernelSendNotificationRequest(int, notify_request_t*, size_t, int);
unsigned int OFFSET_KERNEL_PS4SDK_55 = 0x023D9048;
unsigned int OFFSET_KERNEL_PS4SDK_51 = 0x023D8F38;
unsigned int OFFSET_KERNEL_PS4SDK_43 = 0x022ABE88;

int
main() {
  notify_request_t req;

  bzero(&req, sizeof req);
  switch(kernel_get_fw_version() & 0xffff0000) {
      case 0x4030000:
        strncpy(req.message, "The PS4 SDK has been patched to version 99.9 (firm 4.03)", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_43, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
      case 0x5100000:
        strncpy(req.message, "The PS4 SDK has been patched to version 99.9 (firm 5.1)", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_51, 0x99999999);
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
      case 0x5500000:
        strncpy(req.message, "The PS4 SDK has been patched to version 99.9 (firm 5.5)", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_55, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
  }
  strncpy(req.message, "Your firmware version is not supported", sizeof req.message);
  return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
}

