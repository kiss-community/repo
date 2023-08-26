#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int stat64(char *pathname, struct stat *statbuf) {
  return stat(pathname, statbuf);
}

int fstat64(int fd, struct stat *statbuf) { return fstat(fd, statbuf); }

int fstatat64(int dirfd, char *pathname, struct stat *statbuf, int flags) {
  return fstatat(dirfd, pathname, statbuf, flags);
}

int lstat64(char *restrict pathname, struct stat *statbuf) {
  return lstat(pathname, statbuf);
}

int truncate64(char *path, off_t length) { return truncate(path, length); }

int ftruncate64(int fd, off_t length) { return ftruncate(fd, length); }

off_t lseek64(int fd, off_t offset, int whence) {
  return lseek(fd, offset, whence);
}

int open64(const char *pathname, int flags,
           /* Technically this is undefined behaviour, but the `mode`
            * value is only checked if the relevant flag is set in `flags`
            * so a garbage value will never be read */
           mode_t mode) {
  return open(pathname, flags, mode);
}

struct dirent *readdir64(DIR *dirp) { return readdir(dirp); }

ssize_t pread64(int fd, void *buf, size_t count, off_t offset) {
  return pread(fd, buf, count, offset);
}

ssize_t pwrite64(int fd, void *buf, size_t count, off_t offset) {
  return pwrite(fd, buf, count, offset);
}
