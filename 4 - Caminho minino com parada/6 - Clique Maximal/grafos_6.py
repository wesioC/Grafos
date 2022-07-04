import numpy as np
MAX = 100;
store = [0] * MAX
graph = np.zeros((MAX, MAX))

d = [0] * MAX

def EhClique(b) :
	for i in range(1, b) :
		for j in range(i + 1, b) :
			if (graph[store[i]][store[j]] == 0) :
				return False;
	return True;


def ShowCliques(n,v) :
	cont = 0
	c=[range(n)]
	for i in range(1, n) :
		c.append(store[i])
	for j in c:
		if(j==v):
			cont+=1
	if(cont>0):
		print(c[1:])
		cont =0


def CliquesMaximos(i, l, s, v) :
	for j in range( i + 1, n -(s - l) + 1) :
		if (d[j] >= s - 1) :
			store[l] = j
			if (EhClique(l + 1)) :
				if (l < s) :
					CliquesMaximos(j, l + 1, s, v)
				else :
					ShowCliques(l + 1, v)

def cliquesMaximais(i, l):
    # tamanho Maximal clique
    max_ = 0;
    for j in range(i + 1, n + 1):
        store[l] = j;
        if (EhClique(l + 1)):
            max_ = max(max_, l);
            max_ = max(max_, cliquesMaximais(j, l + 1));
    return max_;

if __name__ == "__main__" :
	#grafo deve ser iniciado pelo V(1)
	edges = [ [ 1, 2 ],
						[ 2, 3 ],
						[ 3, 1 ],
						[ 4, 3 ],
						[ 4, 5 ],
						[ 5, 3 ] ];
	size = len(edges);
	n = 5;

	for i in range(size) :
		graph[edges[i][0]][edges[i][1]] = 1;
		graph[edges[i][1]][edges[i][0]] = 1;
		d[edges[i][0]] += 1;
		d[edges[i][1]] += 1;
	k = cliquesMaximais(0, 1);
	v = int(input('Digite o vertice para encontrar os clique maximal: '))
	CliquesMaximos(0, 1, k, v);