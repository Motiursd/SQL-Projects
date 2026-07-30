import express, { Application, Request, Response } from 'express';
import cors from 'cors';
import packageRoutes from './routes/packageRoutes';

const app: Application = express();

app.use(cors());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.use('/api/v1/packages', packageRoutes);

app.get('/', (req: Request, res: Response) => {
  res.status(200).json({
    message: 'Welcome to Tour Management System API',
  });
});

export default app;
