import os
import time

start = time.time()
tree = os.walk('samples')
dublicate = []
for i, j, files in tree:
    for name in files:
        file_path = i + "\\" + name
        with open(file_path, 'rb') as file:
            data = file.read()
            _hash = 0xffffffff
            poly = 0xedb88320
            for byte in data:
                _hash ^= byte
                for _ in range(8):
                    _hash = (_hash >> 1) ^ (poly & -(_hash & 1))
                _hash ^= 0xffffffff

        if name == 'original.wav':
            original_hash = _hash
        elif original_hash == _hash:
            dublicate.append(name)

end = time.time() - start
print(end, dublicate)
