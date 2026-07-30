import express, { Application, Request, Response } from 'express';
import cors from 'cors';

const app: Application = express();

// Middlewares
app.use(cors());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Test Route
app.get('/', (req: Request, res: Response) => {
  res.status(200).json({
    message: 'Welcome to Tour Management System API',
  });
});

export default app;
