#include <stdio.h>
#include <string.h>
#include <ps5/kernel.h>

typedef struct notify_request {
  char useless1[45];
  char message[3075];
} notify_request_t;


int sceKernelSendNotificationRequest(int, notify_request_t*, size_t, int);
unsigned int OFFSET_KERNEL_PS4SDK_200 = 0x031582C8;
unsigned int OFFSET_KERNEL_PS4SDK_225 = 0x031583A8;
unsigned int OFFSET_KERNEL_PS4SDK_230 = 0x03158548;
unsigned int OFFSET_KERNEL_PS4SDK_250 = 0x03158568;
unsigned int OFFSET_KERNEL_PS4SDK_321 = 0x02209898;
unsigned int OFFSET_KERNEL_PS4SDK_451 = 0x022ABE88;
unsigned int OFFSET_KERNEL_PS4SDK_510 = 0x023D8F38;
unsigned int OFFSET_KERNEL_PS4SDK_550 = 0x023D9048;
unsigned int OFFSET_KERNEL_PS4SDK_650 = 0x0241ACA8;
unsigned int OFFSET_KERNEL_PS4SDK_761 = 0x0240BE58;
unsigned int OFFSET_KERNEL_PS4SDK_800 = 0x0241BE58;

int
main() {
  notify_request_t req;

  bzero(&req, sizeof req);
  switch(kernel_get_fw_version() & 0xffff0000) {
      case 0x2000000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_200, 0x99999999);
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);

      case 0x2250000:
      case 0x2260000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_200, 0x99999999);
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);

      case 0x2300000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_200, 0x99999999);
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);

      case 0x2500000:
      case 0x2700000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_250, 0x99999999);
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);

      case 0x3000000:
      case 0x3100000:
      case 0x3200000:
      case 0x3210000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_321, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
    
      case 0x4000000:
      case 0x4020000:
      case 0x4030000:
      case 0x4500000:
      case 0x4510000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_451, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
      
      case 0x5000000:
      case 0x5020000:
      case 0x5100000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_510, 0x99999999);
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
    
      case 0x5500000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_550, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
    
      case 0x6000000:
      case 0x6020000:
      case 0x6500000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_650, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
    
      case 0x7000000:
      case 0x7010000:
      case 0x7200000:
      case 0x7400000:
      case 0x7600000:
      case 0x7610000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_761, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
    
      case 0x8000000:
      case 0x8200000:
      case 0x8400000:
      case 0x8600000:
        strncpy(req.message, "The PS4 SDK patched to 99.9 - MagicStuff", sizeof req.message);
        kernel_setint(KERNEL_ADDRESS_TEXT_BASE + OFFSET_KERNEL_PS4SDK_800, 0x99999999);  
        return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
    
  }
  strncpy(req.message, "Your firmware version is not supported", sizeof req.message);
  return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
}

