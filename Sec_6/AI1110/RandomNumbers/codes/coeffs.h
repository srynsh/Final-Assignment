// Function declaration
double **createMat(int m, int n);
void readMat(double **p, int m, int n);
void print(double **p, int m, int n);
double **loadtxt(char *str, int m, int n);
double linalg_norm(double **a, int m);
double **linalg_sub(double **a, double **b, int m, int n);
double **linalg_inv(double **mat, int m);
double **matmul(double **a, double **b, int m, int n, int p);
double **transpose(double **a, int m, int n);
void uniform(char *str, int len);
void gaussian(char *str, int len);
void triangular(char *str, int len);
void chi(char *str, int len);
void ray(char *str, int len);
void logarithmic(char *str);
double mean(char *str);
double variance(char *str);
void maxlike(char *str, double a);
// End function declaration

// Defining the function for matrix creation
double **createMat(int m, int n)
{
  int i;
  double **a;

  // Allocate memory to the pointer
  a = (double **)malloc(m * sizeof(*a));
  for (i = 0; i < m; i++)
    a[i] = (double *)malloc(n * sizeof(*a[i]));

  return a;
}
// End function for matrix creation

// Defining the function for reading matrix
void readMat(double **p, int m, int n)
{
  int i, j;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%lf", &p[i][j]);
    }
  }
}
// End function for reading matrix

// Read  matrix from file
double **loadtxt(char *str, int m, int n)
{
  FILE *fp;
  double **a;
  int i, j;

  a = createMat(m, n);
  fp = fopen(str, "r");

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      fscanf(fp, "%lf", &a[i][j]);
    }
  }
  // End function for reading matrix from file

  fclose(fp);
  return a;
}

// Defining the function for printing
void print(double **p, int m, int n)
{
  int i, j;

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
      printf("%lf ", p[i][j]);
    printf("\n");
  }
}
// End function for printing

// Defining the function for norm

double linalg_norm(double **a, int m)
{
  int i;
  double norm = 0.0;

  for (i = 0; i < m; i++)
  {
    norm = norm + a[i][0] * a[i][0];
  }
  return sqrt(norm);
}
// End function for norm

// Defining the function for difference of matrices

double **linalg_sub(double **a, double **b, int m, int n)
{
  int i, j;
  double **c;
  c = createMat(m, n);

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      c[i][j] = a[i][j] - b[i][j];
    }
  }
  return c;
}
// End function for difference of matrices

// Defining the function for inverse of 2x2 matrix

double **linalg_inv(double **mat, int m)
{
  double **c, det;
  c = createMat(m, m);

  det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

  c[0][0] = mat[1][1] / det;
  c[0][1] = -mat[1][0] / det;
  c[1][0] = -mat[0][1] / det;
  c[1][1] = mat[0][0] / det;

  return c;
}
// End  function for inverse of 2x2 matrix

// Defining the function for difference of matrices

double **matmul(double **a, double **b, int m, int n, int p)
{
  int i, j, k;
  double **c, temp = 0;
  c = createMat(m, p);

  for (i = 0; i < m; i++)
  {
    for (k = 0; k < p; k++)
    {
      for (j = 0; j < n; j++)
      {
        temp = temp + a[i][j] * b[j][k];
      }
      c[i][k] = temp;
      temp = 0;
    }
  }
  return c;
}
// End function for difference of matrices

// Defining the function for transpose of matrix

double **transpose(double **a, int m, int n)
{
  int i, j;
  double **c;
  // printf("I am here");
  c = createMat(n, m);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      c[i][j] = a[j][i];
      //  printf("%lf ",c[i][j]);
    }
  }
  return c;
}
// End function for transpose of matrix

// Defining the function for generating uniform random numbers
void uniform(char *str, int len)
{
  int i;
  FILE *fp;

  fp = fopen(str, "w");
  // Generate numbers
  for (i = 0; i < len; i++)
  {
    fprintf(fp, "%lf\n", (double)rand() / RAND_MAX);
  }
  fclose(fp);
}
// End function for generating uniform random numbers

// Defining the function for calculating the mean of random numbers
double mean(char *str)
{
  int i = 0, c;
  FILE *fp;
  double x, temp = 0.0;

  fp = fopen(str, "r");
  // get numbers from file
  while (fscanf(fp, "%lf", &x) != EOF)
  {
    // Count numbers in file
    i = i + 1;
    // Add all numbers in file
    temp = temp + x;
  }
  fclose(fp);
  temp = temp / (i - 1);
  return temp;
}
// End function for calculating the variance of random numbers

// Defining the function for calculating the mean of random numbers
double variance(char *str)
{
  int i = 0, c;
  FILE *fp;
  double x, temp = 0.0;

  fp = fopen(str, "r");
  // get numbers from file
  while (fscanf(fp, "%lf", &x) != EOF)
  {
    // Count numbers in file
    i = i + 1;
    // Add all numbers in file
    temp = temp + x * x;
  }
  double mn = mean(str);
  fclose(fp);
  temp = temp / (i - 1);
  return temp - mn * mn;
}
// End function for calculating the variance of random numbers

// Defining the function for generating Gaussian random numbers
void gaussian(char *str, int len)
{
  int i, j;
  double temp;
  FILE *fp;

  fp = fopen(str, "w");
  // Generate numbers
  for (i = 0; i < len; i++)
  {
    temp = 0;
    for (j = 0; j < 12; j++)
    {
      temp += (double)rand() / RAND_MAX;
    }
    temp -= 6;
    fprintf(fp, "%lf\n", temp);
  }
  fclose(fp);
}
// End function for generating Gaussian random numbers

void triangular(char *str, int len)
{
  int i, j;
  double temp;
  FILE *fp;

  fp = fopen(str, "w");
  // Generate numbers
  for (i = 0; i < len; i++)
  {
    temp = 0;
    for (j = 0; j < 2; j++)
    {
      temp += (double)rand() / RAND_MAX;
    }
    fprintf(fp, "%lf\n", temp);
  }
  fclose(fp);
}

// Function for Rayleigh Distribution 1
void logarithmic(char *str)
{
  int i = 0, c;
  FILE *fp, *fp2;
  double x, temp = 0.0;

  fp = fopen("uni.dat", "r");
  fp2 = fopen(str, "w");
  // get numbers from file
  while (fscanf(fp, "%lf", &x) != EOF)
  {
    temp = -2 * log(1 - x);
    fprintf(fp2, "%lf\n", temp);
  }

  fclose(fp);
  fclose(fp2);

  return;
}

void bernoulli(char *str, int len)
{
  int i, j;
  double temp;
  FILE *fp;

  fp = fopen(str, "w");
  // Generate numbers
  for (i = 0; i < len; i++)
  {
    temp = 0;
    if ((double)rand() / RAND_MAX < 0.5)
      temp = -1;
    else
      temp = 1;
    fprintf(fp, "%lf\n", temp);
  }

  fclose(fp);

  return;
}

void chi(char *str, int len)
{
  FILE *fp = fopen(str, "w");
  int i, j;
  double v;
  double x, y;

  for (i = 0; i < len; i++)
  {
    x = 0;
    for (j = 0; j < 12; j++)
    {
      x += (double)rand() / RAND_MAX;
    }
    x -= 6;
    y = 0;
    for (j = 0; j < 12; j++)
    {
      y += (double)rand() / RAND_MAX;
    }
    y -= 6;
    v = x * x + y * y;
    fprintf(fp, "%lf\n", v);
  }
  fclose(fp);
}

void ray(char *str, int len)
{
  FILE *fp = fopen(str, "w");
  int i, j;
  double v;
  double x, y;

  for (i = 0; i < len; i++)
  {
    x = 0;
    for (j = 0; j < 12; j++)
    {
      x += (double)rand() / RAND_MAX;
    }
    x -= 6;
    y = 0;
    for (j = 0; j < 12; j++)
    {
      y += (double)rand() / RAND_MAX;
    }
    y -= 6;
    v = x * x + y * y;
    fprintf(fp, "%lf\n", sqrt(v));
  }
  fclose(fp);
}

void maxlike(char *str, double A) // Generates Y
{
  int counter = 0;
  double i = 0;
  FILE *fp, *fp2, *fp3;
  double temp = 0.0, x;
  fp = fopen("gau.dat", "r");
  fp2 = fopen(str, "w");
  fp3 = fopen("ber.dat", "r");
  while (fscanf(fp, "%lf", &x) != EOF)
  {
    fscanf(fp3, "%lf", &i);
    temp = A * i + x;
    fprintf(fp2, "%lf\n", temp);
    counter++;
  }

  fclose(fp);
  fclose(fp2);
  fclose(fp3);

  return;
}

double maxlike_proberr(int x)
{
  FILE *fp, *fp2;
  fp = fopen("maxlike.dat", "r");
  fp2 = fopen("ber.dat", "r");
  long count1 = 0;
  long count2 = 0;
  double sum = 0;
  double y;
  double i;
  while (fscanf(fp, "%lf", &y) != EOF)
  {
    fscanf(fp2, "%lf", &i);
    if (x == 1 && i == 1)
    {
      if (y < 0)
        sum++;
      count1++;
    }
    else if (x == -1 && i == -1)
    {
      if (y > 0)
        sum++;
      count2++;
    }

    else if (i == 1)
    {
      count1++;
      continue;
    }
    else
    {
      count2++;
      continue;
    }
  }
  fclose(fp);
  fclose(fp2);
  if (x == 1)
    return sum / count1;
  else
    return sum / count2;
}

void proberr_graph(char *str)
{
  FILE *fp, *fp2;
  // fp = fopen("gau.dat","r");
  fp2 = fopen(str, "w");
  double a = 0.1;
  double temp;
  for (int i = 1; i <= 10; i++)
  {
    maxlike("maxlike.dat", a * i);
    temp = (maxlike_proberr(1) + maxlike_proberr(-1)) / 2;
    fprintf(fp2, "%lf\n", temp);
  }

  fclose(fp2);
  return;
}