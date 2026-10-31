/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _UAPI_LINUX_REALITYTAP_H
#define _UAPI_LINUX_REALITYTAP_H

#include <linux/ioctl.h>
#include <linux/types.h>

#define REALITYTAP_GET_HWINFO	_IO('R', 0x03)
#define REALITYTAP_SETTING_GAIN	_IO('R', 0x05)
#define REALITYTAP_STREAM_MODE	_IO('R', 0x0a)
#define REALITYTAP_GET_F0		_IO('R', 0x11)
#define REALITYTAP_STOP_MODE	_IO('R', 0x12)
#define REALITYTAP_F0_CALIBRATE	_IO('R', 0x13)

#define REALITYTAP_BUFFER_COUNT	16
#define REALITYTAP_DATA_SIZE	1000
#define REALITYTAP_MMAP_SIZE	16384

#define REALITYTAP_BUFFER_VALID		0x55
#define REALITYTAP_BUFFER_FINISHED	0xaa
#define REALITYTAP_BUFFER_INVALID		0xff

/* Preserve the ARM64 vendor ABI, including both legacy link fields. */
struct realitytap_buffer {
	__u8 status;
	__u8 reserved;
	__s16 length;
	__u32 reserved1;
	__aligned_u64 kernel_next;
	__aligned_u64 user_next;
	__s8 data[REALITYTAP_DATA_SIZE];
};

#endif /* _UAPI_LINUX_REALITYTAP_H */
