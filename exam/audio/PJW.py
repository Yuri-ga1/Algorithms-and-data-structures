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
            _hash = 0
            for byte in data:
                _hash = (_hash << 4) + byte
                high_bits = _hash & 0xf0000000
                if high_bits != 0:
                    _hash = (_hash ^ (high_bits >> 24)) & (0xfffffff) 

        if name == 'original.wav':
            original_hash = _hash
        elif original_hash == _hash:
            dublicate.append(name)

end = time.time() - start
print(end, dublicate)